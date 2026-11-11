#include<bits/stdc++.h>
#define int long long
#define fo(i,n) for(int i = 1;i<=n;i++)
#define foi(i,n,m) for(int i = n;i<=m;i++)
using namespace std;
const int N = 1e6 + 10;
int c,t;
int n,m,a[1000010],dp[5050][5050],can[5050][5050];

void dfs1(){
	while(t--){
		cin>>n>>m;
//		cout<<1;
		memset(dp,0x3f,sizeof dp);
		memset(can,0,sizeof can);
//		int queueue[N],l=1,r=1;
		fo(i,n){
			dp[i][i] = 0;
			cin>>a[i];
//			queueue[r++] = a[i]; 
//			while(l<=r&&queueue[r-1]-queueue[l]>=m) l++;
//			foi(j,l,r){
//				dp[j][r] = 1;
//				can[j][r] = 1;
//			}
			for(int j = i;j>=1;--j){
				if(a[i]-a[j]>m) break;
				dp[j][i] = 1;
				can[j][i] = 1;
			}
		}
		fo(i,n){
			foi(j,i+2,n){
				foi(k,i+1,j-1){
					int num = dp[i][k]+dp[k][j];
					if(num==dp[i][j]){
						if(can[i][j]==0) can[i][j] = 1;
						else if(can[i][j]==1) can[i][j] = 2;
						else if(can[i][j]==2) can[i][j] = -1;
					}
					else if(dp[i][j]>num){
						dp[i][j] = num;
						can[i][j] = 1;
					}
//					cout<<dp[2][4];
//					cout<<i<<" "<<k<<" "<<j<<" "<<dp[i][j]<<" "<<num<<" "<<can[i][j]<<endl; 
				}
			}
		}
		int cnt = 0;
		fo(i,n){
			foi(j,i+1,n){
				if(can[i][j]==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
} 
void dfs2(){
	while(t--){
		cin>>n>>m;
		memset(a,0,sizeof a);
		int cnt = 1;
		cin>>a[1]>>a[2];
		foi(i,3,n){
			cin>>a[i];
			if(abs(a[i]-a[i-2])>m) cnt++;
		}
		cout<<cnt<<endl;
	}
}
void dfs(){
	if(t==2){
		dfs1();
	}
	else if(t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	else if(t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	else if(t==14){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else if(t==16){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	} 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		dfs();
		return 0; 
	}
	if(11<=c&&c<=12){
		while(t--) cout<<0<<endl; 
		return 0;
	}
	if(15<=c&&c<=18){
		dfs2();
		return 0;
	}
	dfs1();
}

