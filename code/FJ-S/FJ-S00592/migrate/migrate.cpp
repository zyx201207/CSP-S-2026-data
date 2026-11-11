#include<iostream>
#include<iostream>
using namespace std;
typedef long long ll;
const ll MAXN=307,INF=0x3f3f3f3f3f3f3f3f;

ll arr[MAXN],n,d,dis[MAXN][MAXN],cnt[MAXN][MAXN],res=0;

void solve(){
	cin>>n>>d;res=0;
	for(int i=0;i<n;i++)cin>>arr[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			cnt[i][j]=1;
			if(arr[i]-arr[j]<=d){
				dis[i][j]=1;
			}else{
				dis[i][j]=INF;
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ll tmp=dis[i][k]+dis[k][j];
				if(tmp<dis[i][j]){
					dis[i][j]=tmp;
					cnt[i][j]=min(10ll,cnt[i][k]*cnt[k][j]);
				}
				else if(tmp==dis[i][j]){
					cnt[i][j]+=min(10ll,cnt[i][k]*cnt[k][j]);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(cnt[i][j]==2)res++;
		}
	}
	cout<<res<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int C,T;cin>>C>>T;
	for(int i=0;i<T;i++)solve();
	return 0;
}

