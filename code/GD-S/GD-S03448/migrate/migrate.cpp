#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[5050];
int f[5050][5050];
int cnt[5050][5050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			cnt[i][i]=1;
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					f[i][j]=1;
				}else break;
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(f[i][j]==f[i][k]+f[k][j])ans++;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
} 
