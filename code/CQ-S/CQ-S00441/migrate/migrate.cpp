#include<bits/stdc++.h>//纯暴力（嗯对这个不止一小时） 
using namespace std;
int c,t;
int n;
long long d;
long long a[5005];
long long ans[5005][5005],s[5005][5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)s[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1){
				if(a[i]-a[i-1]>d)ans[i-1][i]=-1;
				else ans[i-1][i]=1;
			}
		}
		for(int len=3;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if(a[j]-a[i]<=d)ans[i][j]=1;
				else{
					ans[i][j]=LONG_LONG_MAX;
					for(int k=i+1;k<j;k++){
						if(ans[i][k]==-1||ans[k][j]==-1){
							ans[i][j]=-1;
							break;
						}
						ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
					}
				}
			}
		}//最短路径
		long long ans1=0;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if(ans[i][j]==-1)continue;
				if(ans[i][j]==1){
					s[i][j]=1;
					continue;
				}
				for(int k=i+1;k<j;k++){
					if(ans[i][k]+ans[k][j]==ans[i][j]&&ans[k][j]==1){
						s[i][j]+=s[i][k];
					}
				}
				if(s[i][j]==2)
				{
					ans1++;
				}
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
}
