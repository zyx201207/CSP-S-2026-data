#include <bits/stdc++.h>
using namespace std;

int x[100005];

int tp[105][105];
int fly[105][105][105];
int top=1;
vector<int> g[100005];

int n,d;

void dfs(int orx, int x, int y, int cnt){
	if (x>n) return;
	if (x==y){
		fly[++tp[orx][y]][orx][y]=cnt;
		return;
	}
	for (auto nx:g[x]){
		dfs(orx, nx, y, cnt+1);
	}
}

int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		for (int i=1;i<=105;i++){
			for (int j=1;j<=105;j++){
				tp[i][j]=0;
			}
		}
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (x[j]-d<=x[i]){
					g[x[i]].push_back(x[j]);
				}else break;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				dfs(x[i], x[i], x[j], 0);
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				int mn=1e9,cnt=0;
				cout<<i<<" "<<j<<"  ";
				for (int k=1;k<=tp[i][j];k++){
					cout<<fly[k][i][j]<<endl;
					mn = min(mn,fly[k][i][j]);
				}
				for (int k=1;k<=tp[i][j];k++){
					if (mn == fly[k][i][j]) cnt++;
				}
				if (cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
