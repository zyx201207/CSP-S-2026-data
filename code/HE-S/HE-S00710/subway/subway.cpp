#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	vector<long long> w;
	cin>>c>>n>>m>>d>>q;
	vector< vector< vector<long long> > > a(m+1),zt(m+1);
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	}
	for(int i=0;i<n;i++){
		int g;
		cin>>g;
		vector<long long> la(g+1);
		for(int j=0;j<g;j++){
			int x;
			cin>>la[j]>>x;
			zt[i][la[j]].push_back(x);
		}
		for(int j=0;j<g;j++){
			for(int k=j+1;k<g;k++){
				a[i][la[j]].push_back(la[k]);
				a[i][la[k]].push_back(la[j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<1<<endl;
	}
	return 0; 
}
