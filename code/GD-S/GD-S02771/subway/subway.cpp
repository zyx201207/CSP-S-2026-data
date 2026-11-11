#include <bits/stdc++.h>
using namespace std;
vector<int> w,k,x,y;
vector<vector<int>>a,t;
int m,n,c,d,q,A,T,sum,_max;
bool visitedway[505];
void DFS(int o){
	for(int i=0;i<n;i++){
		visitway[i]= 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	w.resize(m);
	k.resize(n);
	a.resize(n,vector<int>(m,0));
	t.resize(m,vector<int>(m,2e+1));
	x.resize(q);
	y.resize(q);
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>A>>T;
			a[i][A]=T;
		}
	}
	for(int r=0;r<q;r++){
		cin>>x[r]>>y[r];
		sum+=w[x[r]]+w[y[r]];
		for(int j=0;j<n;j++){
			if(a[j][x[r]]!=0&&a[j][y[r]]!=0)_max=min(_max,a[j][x[r]]+ a[j][y[r]]); 
		}
		//DFS(o);
		cout<<_max<<endl; 
	}
	return; 
}
