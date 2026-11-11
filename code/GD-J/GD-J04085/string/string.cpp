#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=2e5+5;
int n;
i64 a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	{
		int i=1,j=n;
		i64 k=0;
		for(;i<=n;++i){
			i64 rem=a[i];
			for(;j>=1&&rem>a[j]-k;--j,k=0){
				if(c[i]!=c[j]){
					ans+=a[j]-k;
					// cout<<i<<' '<<j<<' '<<a[j]-k<<'\n';
				}
				rem-=a[j]-k;
			}
			if(c[i]!=c[j]){
				ans+=rem;
				// cout<<i<<' '<<j<<' '<<rem<<'\n';
			}
			k+=rem;
		}
	}
	cout<<ans/2;
}