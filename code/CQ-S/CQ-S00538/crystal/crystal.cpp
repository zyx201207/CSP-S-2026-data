#include<bits/stdc++.h>
using namespace std;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=5e5;
	const int INF=2e9;
	int n,ans;
	LL m,a[N+5],ps[N+5];
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			ps[i]=ps[i-1]+a[i];
		}
		int l,r,mid,x;
		for(int i=1;i<=n;i++){
			l=1,r=i-1,x=i;
			while(l<=r){
				mid=l+r>>1;
				if(a[i]*(i-mid+1)-(ps[i]-ps[mid-1])<=m){
					x=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans=max(ans,i-x+1);
		}
		cout<<ans<<"\n";
		return 0;
	}
}
int main(){
	cs::main();
	return 0;
}
//password: Oct31==Dec25?
//14:35 Solve T1
