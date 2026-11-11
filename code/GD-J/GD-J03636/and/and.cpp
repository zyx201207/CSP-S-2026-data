#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll n,m,cnt,mx,ar[N],dp[N][30],pos[N],ans,npos[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		pos[i]=i;
	}
	for(int i=1;i<=n;i++){
		ll a=ar[i];
		for(int j=1;j<=31;j++){
			dp[i][j]=a%2;
	//		cout<<dp[i][j]<<' ';
			a/=2;
		}
	//	cout<<endl;
	}
	for(int i=31;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(dp[pos[j]][i]){
			//	cout<<j<<" ";
				npos[++cnt]=pos[j];	
			}
		}
		if(cnt>=m){
		//	cout<<cnt<<" ";
			n=cnt;
			for(int j=1;j<=n;j++){
				pos[j]=npos[j];
				npos[j]=0;
			}
			cnt=0;
			ans+=(1<<i-1);
		}
		cnt=0;
	}
	cout<<ans;
/*
5 3
31 3 1 15 7
*/
	return 0;
}

