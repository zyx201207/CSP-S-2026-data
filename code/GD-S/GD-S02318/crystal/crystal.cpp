#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define gc getchar
#define pb emplace_back
inline ll re(){
	ll x=0,f=1; char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=x*10+(c-48);
	return x*f;
}
constexpr int N = 5e5+3;

namespace solve{
	int n;
	ll m,a[N],s[N];
	
	void sol(){
		n=re(); m=re();
		for(int i=1;i<=n;i++)a[i]=re();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		int l=1,r=n,res;
		auto check=[&](int p)->bool{
			for(int i=p;i<=n;i++)
				if(a[i]*p-(s[i]-s[i-p])<=m)return 1;
			return 0;
		};
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))res=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<res<<'\n';
	}
}//O(n\log n)

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--)solve::sol();
}
