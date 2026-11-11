#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200005],n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n,lnum=a[1],rnum=a[n],ans=0;
	while(l<=r){
		if(c[r]==c[l]){
			ll mi=min(lnum,rnum);
			lnum-=mi,rnum-=mi;
			if(lnum==0)lnum=a[++l];
			if(rnum==0)rnum=a[--r];
		}else{
			ll mi=min(lnum,rnum);
			lnum-=mi,rnum-=mi,ans+=mi;
			if(lnum==0)lnum=a[++l];
			if(rnum==0)rnum=a[--r];
		}
	}
	cout<<ans;
	return 0;
}

