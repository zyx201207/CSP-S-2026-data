#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
struct node{
	ll x,t;
	bool operator <(const node &no)const{
		return no.t<t;
	}
};
priority_queue<node> q;
ll T,a[N],dis[N];
set<ll> s[N];
vector<node> e[N];
bool vis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--){
		ll n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>d)break;
				e[i].push_back({j,1});
				e[j].push_back({i,1});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s[i].clear();
				dis[j]=1e9;
				vis[j]=false;
			}
			while(!q.empty())q.pop();
			q.push({i,0});
			dis[i]=0;
			while(!q.empty()){
				node tp=q.top();
				q.pop();
				vis[tp.x]=true;
				for(int j=0;j<e[tp.x].size();j++){
					node v=e[tp.x][j];
					if(dis[v.x]>dis[tp.x]+v.t){
						dis[v.x]=dis[tp.x]+v.t;
						s[v.x].clear();
						s[v.x].insert(tp.x);
						if(!vis[v.x])q.push({v.x,dis[v.x]});
					}else{
						if(dis[v.x]==dis[tp.x]+v.t)s[v.x].insert(tp.x);
					}
				} 
			}
			for(int j=i+1;j<=n;j++)if(s[j].size()==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4 
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 
111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992
 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/

