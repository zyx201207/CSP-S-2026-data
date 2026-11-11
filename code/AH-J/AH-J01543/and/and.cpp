// Obviously, I cannot solve this problem.
// Comedy? Tragedy? Bittersweet?
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=2e5+5,M=32;
int a[N][M],c[N],d[N],cnt[N],n,m,k=0;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for(int i=1,x;i<=n;i++) cin>>x,ans=max(ans,x);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		int ans=0;
		for(int i=1,x;i<=n;i++) cin>>x,ans&=x;
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=2000&&m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				ans=max(ans,c[i]&c[j]);
		}
		cout<<ans<<"\n";
		return 0;
	}
	sort(c+1,c+n+1);
	int ans=(1<<30)-1;
	for(int i=n;i>=n-m+1;i--)
		ans&=c[i];
	cout<<ans<<"\n";
	return 0;
}
