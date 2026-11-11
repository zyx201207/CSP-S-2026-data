#include <bits/stdc++.h>
using namespace std;
int const M=1e5*5+10;
int const N=510;
int const Q=1e5+10;
int c,n,m,d,q;
int w[M];
int k[N];
int a[M],t[M];
int x[Q],y[Q];
int ans[Q];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
    	cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	sort(k,k+n,cmp);
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
		ans[i]=w[x[i]]+w[y[i]];
	}
	bool fx[q][n]={0},fy[q][n]={0};
	for(int v=0;v<q;v++){
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(a[j]==x[i]){
					fx[v][i]=1;
				}
				if(a[j]==y[i]){
					fy[v][i]=1;
				}
			}
		}
	}
	for(int v=0;v<q;v++){
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(fx[v][i]&&fy[v][i]){
					ans[v]+=t[x[v]]+t[y[v]];
					break;
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans;
	}
	return 0;
}

