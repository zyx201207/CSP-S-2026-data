#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
long long n,m,d,p,cc,a[N][N],w[N],k[N],t[N][N];
vector<long long>v[M],vz[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(i);
			vz[i].push_back(a[i][j]);
		}
	}
	while(p--){
		long long mn=1e9,x,y;
		cin>>x>>y;
		if(v[x]==v[y]){
			cout<<w[x]+w[y]<<endl;
		}else{
			for(int i=0;i<vz[v[x]].size();i++){
				for(int j=0;j<vz[v[y]].size();j++){
					if(vz[v[x]][i]==vz[v[y]][j]){
						mn=min((long long)mn,(long long)(t[v[y]][j]+t[v[x]][i]));
					}
				}
			}
			cout<<mn+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
