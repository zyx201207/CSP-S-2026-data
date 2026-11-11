#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],mj[200005];
struct node{
	int now,sum;
};
ll ans;
vector<int> v[200005];
void bfs(ll x,ll y){
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		node m=q.front();
		q.pop();
		int no=m.now,su=m.sum;
		if(no==y){
			mj[su]++;
			continue;
		}
		for(auto i:v[no]){
			q.push({i,++su});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				bfs(i,j);
				bool f=0;
				cout<<"!"<<i<<" "<<j<<"\n";
				for(int k=1;k<=j-i+1;k++){
					cout<<k<<" "<<mj[k]<<"\n";
					if(mj[k]==2&&f==0){
						ans++;
						break;
					}
				}
				for(int k=1;k<=j-i+1;k++){
					mj[k]=0;
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}
