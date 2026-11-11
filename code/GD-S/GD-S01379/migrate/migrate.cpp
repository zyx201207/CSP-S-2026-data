#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,sum;
int a[2000000];
int len[1010][1010];
int cnt[1010][1010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		int fl=1,st;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			cnt[i][i]=1;
			for(int j=i+1;j<=n;j++){
				len[i][j]=len[j][i]=1e10;
				cnt[i][j]=cnt[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
				len[i][j]=len[j][i]=1;
				cnt[i][j]=cnt[j][i]=1;
			}
		}
		for(int x=1;x<=n;x++){
			for(int j=1;j+x<=n;j++){
				for(int k=1;k<=n;k++){
					int i=j+x;
					if(k==i||k==j)continue;
					if(len[i][k]==1e10||len[j][k]==1e10)continue;
					if(len[i][k]+len[j][k]<len[i][j]){
						len[i][j]=len[j][i]=len[i][k]+len[j][k];
						cnt[i][j]=cnt[j][i]=1;
					}
					else if(len[i][k]+len[k][j]==len[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
						cnt[j][i]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
