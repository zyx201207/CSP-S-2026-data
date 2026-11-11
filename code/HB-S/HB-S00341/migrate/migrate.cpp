#include<iostream>
#include<queue>
using namespace std;

int cid,t,n,ans=0,car[5005][5005];
long long d,a[5005],dis[5005],cnt[5005];
queue<int> q;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cid>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					car[i][j]=1;
					car[j][i]=1;
				}
				else{
					car[i][j]=0;
					car[j][i]=0;
				}
			}
		}
		for(int s=1;s<=n;s++){
			for(int i=s+1;i<=n;i++){
				cnt[i]=0;
				dis[i]=6e18;
			}
			dis[s]=0;
			cnt[s]=1;
			q.push(s);
			while(!q.empty()){
				int topp=q.front();
				//cout<<s<<" "<<topp<<"\n";
				q.pop();
				for(int j=topp+1;j<=n;j++){
					if(!car[topp][j]) break;
					if(dis[j]<dis[topp]+1) continue;
					cnt[j]+=cnt[topp];
					//cout<<j<<" ";
					if(dis[j]==6e18){
						dis[j]=dis[topp]+1;
						q.push(j);
					} 
				}
				for(int j=topp-1;j>s;j--){
					if(!car[topp][j]) break;
					if(dis[j]<dis[topp]+1) continue;
					cnt[j]+=cnt[topp];
					//cout<<j<<" ";
					if(dis[j]==6e18){
						dis[j]=dis[topp]+1;
						q.push(j);
					} 
				}
				//cout<<"\n\n";
			}
			for(int i=s+1;i<=n;i++){
				if(cnt[i]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}	
