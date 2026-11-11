#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
bool subA,subB,subC;
int n,d,ans;
int a[N],sum[N],tbA,tbB;
void solve(){
	ans=0;
	cin>>n>>d;
	subA=1;subB=1;
	tbB=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)tbA=a[i]-a[i-1]; 
		if(i>=3)if(a[i]-a[i-1]!=tbA)subA=0;
		sum[i]=sum[i-1]+a[i]; 
	}
	if(subA){
		int lim=d/tbA;
		if(d<=tbA){
			cout<<"0\n";
			return ;
		}
		for(int i=lim*2;i<=n;i++)ans++;
		cout<<ans<<"\n";
	}
	if(n>=5000){
		cout<<"0\n";
		return ;
	}
	for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d)continue;
				int p=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
				//cout<<i<<","<<j<<":"<<p<<"\n";
				if(p>i+1 && p<j){
				if(a[j]-a[p]<=d){
				if(a[j]-a[p-1]<=d){
				if(a[j]-a[p-2]>d){
					ans++;
				}
				}
				}
				}
		} 
	} 
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T; 
	while(T--)solve();
	return 0;
} 
/*

*/
