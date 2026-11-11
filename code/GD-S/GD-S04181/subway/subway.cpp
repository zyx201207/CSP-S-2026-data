#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100010],a[10010][10010],t[10010],k[10010],x[10010],y[10010],min1[1000][1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;

	
	
	for(int i=0;i<m;i++) cin>>w[i];	
	
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i];
			}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			min1[i][j]=0x3f3f3f;
			if (i==j) min1[i][j]=t[i]+w[i];
	}}
	for(int i=0;i<n;i++){
		for(int j=1;j<k[i];j++){
			min1[a[i][j-1]][a[i][j]]=w[a[i][j-1]]+t[i]+w[a[i][j]]; 
			min1[a[i][j]][a[i][j-1]]=min1[a[i][j-1]][a[i][j]];
			}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int z=0;z<m;z++){
			min1[i][z]=min(min1[i][z],min1[i][j]+min1[j][z]+t[z]); 
			}
	}}
	
	for(int r=0;r<q;r++) {
	cin>>x[r]>>y[r];}
	for(int r=0;r<q;r++) {
	cout<<min1[x[r]][y[r]]-t[y[r]]<<" ";
	}
	return 0;
}


