#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
long long n,m,d,q,w[M],ans=0;
int k[505],z[505][505];
vector<long long>t[505];
vector<int>a[505];
vector<int>dt[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int donk=1;
		for(int j=1;j<=2*k[i];j++){
			if(j%1==1){
				int nico;
				cin>>nico;
				a[i].push_back(nico);
				dt[nico].push_back(i);
			}
			else{
				int nico;
				cin>>nico;
				t[i].push_back(nico);
				donk++;
			}
		}
	}
	while(q){
		int x,y;
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<ans<<'\n'; 
		q--;
	}
	return 0;
}
