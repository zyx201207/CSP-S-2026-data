#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
vector<long long>p;
using pii=pair<long long,long long>;
vector<vector<long long> > res,vid,vid2,cnted;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		p=vector<long long>(n+1);
		res=vector<vector<long long> >(n+1,vector<long long>(n+1));
		vid=vector<vector<long long> >(n+1,vector<long long>(n+1,0));
		vid2=vector<vector<long long> >(n+1,vector<long long>(n+1,0));
		cnted=vector<vector<long long> >(n+1,vector<long long>(n+1,0));
		for(long long i=0;i<=n;i++){
			for(long long j=0;j<=n;j++){
			if(i==j) res[i][j]=0;
			else res[i][j]=1000000000000000;
		}
		}
		for(long long i=1;i<=n;i++){
			cin>>p[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(p[j]-p[i]<=d){
					res[i][j]=1;
					res[j][i]=1;
				}else{
					break;
				}
			}
		}
		map<long long,long long>s;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				for(long long k=1;k<=n;k++){
					res[i][j]=min(res[i][j],res[i][k]+res[k][j]);
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j)continue;
				for(long long k=1;k<=n;k++){
					if(k==i||k==j)continue;
					if(res[i][j]==res[i][k]+res[k][j]&&res[i][j]!=1){
						if(vid[i][j]==0){
						vid[i][j]=k;
						vid[j][i]=k;
						}else{
							if(k!=vid[i][j]){
								if(cnted[i][j]==0){
									cnted[i][j]=1;
									vid2[i][j]=k;
									vid2[j][i]=k;
									ans++;
								}
								if(cnted[i][j]==1&&k!=vid2[i][j]){
									ans--;
									cnted[i][j]=2;
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		
	} 
	cout.flush();
	return 0; 
}
