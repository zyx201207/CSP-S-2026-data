#include<bits/stdc++.h>
#define _ti_mu (string)("migrate")
#define tiaoshi 0
#define t_ if(tiaoshi)
using namespace std;
using ll = long long;using vi = vector<int>;
using pii = pair<int,int>;using vll = vector<ll>;
using ai2 = array<int,2>;
int n;
ll d;
ll dist[5005][5005];
ll cnt[5005][5005];
vector<ai2> g;
void floyd(int p){
	memset(dist,0x3f,sizeof dist);
	memset(cnt,0x00,sizeof cnt);
	//build edge
	for(const ai2 i : g){
		int u=i[0],v=i[1];
		dist[u][v] = 1;
		dist[v][u] = 1;
		cnt[u][v]=cnt[v][u]=1;
	}
	//floyd
	for(int i = 1;i<=p;i++){
		for(int j = 1;j<=p;j++){
			if(i==j) continue;
			for(int k = 1;k<=p;k++){
				if(i==k||j==k) continue;
				if(dist[i][j]+(ll)dist[j][k]<dist[i][k]){
					dist[i][k]=dist[i][j]+dist[j][k];
					cnt[i][k]=(ll)cnt[i][j]*cnt[j][k];
				}
				else if(dist[i][j]+(ll)dist[j][k]==dist[i][k]){
					cnt[i][k]+=(ll)cnt[i][j]*cnt[j][k];
					//now ignore
				}
			}
		}
	}
}
ll a[200005];
void main1(){
	cin>>n>>d;
	g.clear();
	/*g = {{1,2},{1,3},{2,3},{2,4},{3,4}};
	floyd(4);
	*/
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<n;i++){
		int p = i+1;
		while(p<=n){
			if((ll)a[p]-(ll)a[i]<=d){
				g.push_back({i,p});
			}
			else{
				break;
			}
			p++;
		} 
	}
	floyd(n);
	t_ for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++) cout<<dist[i][j]<<" ";
		cout<<endl;
	}
	t_ cout<<"dist-^ cnt-v\n";
	t_ for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++) cout<<cnt[i][j]<<" ";
		cout<<endl;
	}
	int ans = 0;
	for(int i = 1;i<n;i++){
		for(int j = i+1;j<=n;j++){
			if((ll)dist[i][j]<1e15 && cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	freopen((_ti_mu+".in").c_str(),"r",stdin);
	freopen((_ti_mu+".out").c_str(),"w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		main1();
	}
	return 0;
}
//3279
