/*
	migrate
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	int id,st;
};

vector<node>need[N];

int c,T;

ll pos[N];
int sum[N];
int f[3000][3000][20];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)need[i].clear();
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		} 
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(pos[i]+d>=pos[j]){
					f[i][j][1]++;
					need[j].push_back({i,1});
					for(auto a:need[i]){
						f[a.id][j][a.st+1]++;
						if(f[a.id][j][a.st+1]>2){
							int tmp=f[a.id][j][a.st+1];
							ans-=tmp*(tmp+1)/2;
							tmp++;
							ans+=tmp*(tmp+1)/2;
						}
						else if(f[a.id][j][a.st+1]==2){
							ans++;
						}
						
						if(pos[j]+d>=pos[j+1]){
							need[j+1].push_back({a.id,a.st+1});
						}
					}
				}
				else{
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
