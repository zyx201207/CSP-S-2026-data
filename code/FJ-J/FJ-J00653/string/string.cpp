#include<bits/stdc++.h>
using namespace std;
long long n,l1,r1,ans;
struct node{
	long long k;
	char c;
}a[200005];
node l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	l1=1,r1=n;
	while(l1<r1){
		if(l.k==0){
			l.k=a[l1].k;
			l.c=a[l1].c;
		}
		if(r.k==0){
			r.k=a[r1].k;
			r.c=a[r1].c;
		}
		if(r.k>=l.k){
			if(r.c!=l.c) ans+=l.k;
			r.k-=l.k;
			l.k=0;
		}
		else{
			if(r.c!=l.c) ans+=r.k;
			l.k-=r.k;
			r.k=0;
		}
		if(l.k==0) l1++;
		if(r.k==0) r1--;
	}
	if(ans<=1) cout<<"0";
	else cout<<ans;
	return 0;
}
