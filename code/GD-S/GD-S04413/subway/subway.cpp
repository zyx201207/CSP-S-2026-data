#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
vector<int> a;
vector<pair<int,int> > e;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	vector<int> a(m);
	e.resize(q);
	vector<vector<int> > jz(n+d,vector<int>(n+d,300000));
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	for(int i=0;i<m+n;i++){
		jz[i][i]=0;
	}
	int k;
	int t1,t2;
	for(int i=0;i<n;i++){
		cin >> k;
		for(int j=0;j<k;j++){
			cin >> t1>> t2;
			jz[t1-1][m+i]=jz[m+i][t1-1]=t2;
		}
	}
	
	
	for(int i=0;i<q;i++){
		cin >> e[i].first >> e[i].second ;
		e[i].first-=1;e[i].second-=1;
	}

	for(int i=0;i<m+n;i++){

		for(int j=0;j<m+n;j++){
			for(int k=0;k<m+n;k++){
				if (jz[j][k]>jz[j][i]+jz[i][k]&&i!=j){
					jz[k][j]=jz[j][k]=jz[j][i]+jz[i][k];
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		int st=e[i].first;
		int ed=e[i].second ;
		if(st==ed){
			cout<<0;
			continue;
		}
		int t=0;
		t+=a[st]; 
		t+=a[ed]; 
		cout <<t+jz[st][ed]<<endl;
	}
	return 0;
} 
