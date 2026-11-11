#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
const int M = 6e3 + 5;
const int inf = 1e18;

int _, c, n, m, tot, ans, a[N], ls[N], st[N];
int dp[M][M];
int mn[M][M];
int fl[M][M];

void solve(){
	tot=ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn[i][i]=0;
		dp[i][i]=1;
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	st[++tot]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int op=0;
			for(int k=i;k<j;k++){
				if(a[k]+m>=a[j]){
					mn[i][j]=mn[i][k]+1;
					fl[i][j]=k;
					op=1;
					break;
				}
			}
			if(!op){
				st[++tot]=j;
				break;
			}
		}
	}
	st[tot+1]=n+1;
	for(int cc=1;cc<=tot;cc++){
		for(int i=st[cc];i<st[cc+1];i++){
			for(int j=i+1;j<st[cc+1];j++){
				dp[i][j]=0;
				for(int k=fl[i][j];k<j;k++){
					if(mn[i][j]==mn[i][k]+1){
						dp[i][j]+=dp[i][k];
						if(dp[i][j]>2)break;
					}
				}
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
}

void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||a[2]-a[1]>m){
		cout<<"0\n";
		return;
	}
	int op=0;
	for(int i=2;i<=n;i++){
		if(a[1]+m<a[i]){
			op=i-2;
			break;
		}
	}
	if(op<2){
		cout<<"0\n";
		return;
	}
	int po=2*op-1;
	if(po>n){
		cout<<"0\n";
		return;
	}
	cout<<n-po<<"\n";
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> _;
	if(11<=c&&c<=12){
		while(_--){
			solve1();
		}
	}
	else{
		while(_--){
			solve();
		}
	}
}

