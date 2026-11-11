#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct node{
	long long x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=1;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long p;char q;
		scanf("%lld %c",&p,&q);
		if(a[cnt-1].c==q){
			a[cnt-1].x+=p;
		}else{
			a[cnt].x=p;a[cnt].c=q;
			cnt++;
		}
	}
	cnt--;
	int l=1,r=cnt;
	while(l<r){
		if(a[l].x==0)l++;
		if(a[r].x==0)r--;
		long long t=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c){
			ans+=t;
		}
		a[l].x-=t;a[r].x-=t;
	}
	cout<<ans;
	return 0;
}
