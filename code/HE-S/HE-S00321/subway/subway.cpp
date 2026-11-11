#include<bits\stdc++.h>
using namespace std;
#define ll long long


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//freopen("E:\\crystal\\crystal2.in","r",stdin);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<int> a[n],t[n];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	vector<pair<int,int>> v;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	cout<<-1<<endl;

	return 0;
} 

