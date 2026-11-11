#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n;
long long d,a[N];
int far[N],pre[N],nxt[N];

void SolveA(){
	long long stp=d/(a[2]-a[1]);
	if(stp==0 || stp==1){
		cout<<"0\n";
		return ;
	}
	cout<<max(0ll,n-2*stp+1ll)<<"\n";
}

void SolveB(){
	int key,flag=0;
	long long sum1=0,sum2=0,sum3=0,sum4=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]<=d && a[n]-a[i]<=d){
			key=i;
			flag++;
		}
	}
	if(flag>1){
		cout<<"0\n";
		return ;
	}
	for(int i=1;i<key;i++){
		if(a[key+1]-a[i]>d){
			sum1++;
		}
		if(a[key+1]-a[i]<=d && a[key+2]-a[i]>d){
			sum2++;
		}
	}
	for(int i=key+1;i<=n;i++){
		if(a[i]-a[key-1]>d){
			sum3++;
		}
		if(a[i]-a[key-1]<=d && a[i]-a[key-2]>d){
			sum4++;
		}
	}
	//cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<"\n";
	cout<<sum1*sum4+sum2*sum3<<"\n";
	return ;
}

void Solve(){
	int dp[310][310];
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if(a[j]-a[i]<=d) dp[i][j]=1;
			for(int k=i+1;k<=j-1;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			int cnt=0;
			for(int k=i+1;k<=j-1;k++){
				if(dp[i][k]+dp[k][j]==dp[i][j]){
					cnt++;
				}
			}
			ans+=(cnt==2);
			if(cnt==-1){
				cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
				for(int k=i+1;k<=j-1;k++){
					if(dp[i][k]+dp[k][j]==dp[i][j]){
						cout<<-k<<"\n";
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}

		if(c>=11 && c<=12) SolveA();
		else if(c>=13 && c<=14) SolveB();
		else Solve();
	}
	return 0;
}
