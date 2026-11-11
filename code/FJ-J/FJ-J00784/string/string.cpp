#include<bits/stdc++.h>
using namespace std;
long long n,t,c,l,r,lq,rq,ans;
char ml,la,ra;
bool f;
struct node{
	long long q;
	char a;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].a;
	}
	l=0,r=n;
	ra=a[r].a;
	rq=a[r].q;
	while(l<r){
		if(rq>lq) la=a[++l].a,lq=a[l].q;
		else ra=a[--r].a,rq=a[r].q;
		t+=min(lq,rq);
		
		if(la!=ra) ans+=min(rq,lq);
		if(lq<=rq) rq-=lq,lq=0;
		else lq-=rq,rq=0;
	}
	cout<<ans;
	return 0;
}
