#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
namespace yyh{
	int n,m,a[500005],s[500005];
	signed main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
			int l=1,r=i-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(s[i-1]-s[mid-1]>=(i-mid)*a[i]-m)r=mid-1,ans=max(ans,i-mid+1);
				else l=mid+1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	yyh::main();
	cerr<<"Time: "<<(double)clock()<<"ms";
	return 0;
}
/*
g++ -std=c++14 -O2 -Wl,-stack=100000000 crystal.cpp -o crystal.exe
crystal.exe < crystal1.in > a.out
fc a.out crystal1.ans
crystal.exe < crystal2.in > a.out
fc a.out crystal2.ans
crystal.exe < crystal3.in > a.out
fc a.out crystal3.ans
crystal.exe < crystal4.in > a.out
fc a.out crystal4.ans

*/
