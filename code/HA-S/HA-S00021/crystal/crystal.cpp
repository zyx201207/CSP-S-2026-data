#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=500003;

ll read(){
	ll x=0,f=1,ch=getchar();
	if(ch<48||ch>57){
		if(ch==45){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int n,ans;

ll a[maxn],s[maxn],m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(a[i]*mid-s[i]+s[i-mid]<=m){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l);
	}
	cout<<ans<<'\n';
	return 0;
}
