#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	vector<int> kou_ting(m);
	for(int i=0;i<m;++i){
		cin>>kou_ting[i];
	}
	vector<vector<pair<int,int>>> ting_tai(n);
	for(int i=0,k;i<n;++i){
		cin>>k;
		for(int j=0,ai,ti;j<k;++j){
			cin>>ai>>ti;
			ting_tai[i].emplace_back(ai,ti);
		}
	}
	vector<pair<int,int>> plan(p);
	vector<long long> times(m);
	for(int i=0;i<p;++i){
		cin>>plan[i].first>>plan[i].second;
		int train,time=kou_ting[plan[i].first]+kou_ting[plan[i].second];
		for(int j=0;j<n;++i){
				if(ting_tai[j][0].first==plan[i].first){
					train=j;
			}
		}
		while(ting_tai[train][1].first!=plan[i].second){
			time=ting_tai[train][0].second+ting_tai[train][1].second;
			for(int j=0;j<n;++j){
				if(ting_tai[j][0].first==ting_tai[train][1].first){
					train=j;
					break;
				}
			}
		}
		cout<<time<<"\n";
	}
	
	return 0;}
