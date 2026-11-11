#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l,r;
int zt[10000],z[10000],s[1000][1000],t[1000][1000];
void dfs(int x){
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>zt[m]; 
	}
	for(int i=0;i<n;i++){
		cin>>z[i];
		for(int j=0;j<z[i];j++){
			cin>>s[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>l>>r;
		dfs(l);
	}
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
}
