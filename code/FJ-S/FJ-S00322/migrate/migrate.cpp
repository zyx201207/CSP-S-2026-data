#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[200024],ans[200024],num[200024];
bool f[200024];
struct node{
	long long v,w;
};
vector <node> vec[200024];
void dijkstra(long long s){
	num[s]=0;
	for(int i = 1;i <= n;i++){
		long long u=-1,minx=1e18;
		for(int j = 1;j <= n;j++){
			if(minx>num[j]&&!f[j]){
				minx=num[j];
				u=j;
			}
		}
		if(u==-1)return;
		f[u]=1;
		for(auto i:vec[u]){
			if(num[i.v]>num[u]+i.w){
				num[i.v]=num[u]+i.w;
			}
		}
	}
}
void dijkstra1(long long s){
	num[s]=0;
	for(int i = 1;i <= n;i++){
		long long u=-1,minx=1e18;
		for(int j = 1;j <= n;j++){
			if(minx>num[j]&&!f[j]){
				minx=num[j];
				u=j;
			}
		}
		if(u==-1)return;
		f[u]=1;
		for(auto i:vec[u]){
			if(num[i.v]==num[u]+i.w){
				ans[i.v]++;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n+8;i++){
			f[i]=0;
			num[i]=1e18+24;
			ans[i]=0;
			vec[i].clear();
		}
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			int j=i-1;
			while(j>0){
				if((x[i]-x[j])<=d){
					vec[i].push_back({j,1});
					vec[j].push_back({i,1});
				}else{
					break;
				}
				j--;
			}
		}
		dijkstra(1);
		for(int i = 1;i <= n+8;i++){f[i]=0;}
		dijkstra1(1);
		long long sum=0;
		for(int i = 1;i <= n;i++){
			if(ans[i]==2){
				sum++;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
