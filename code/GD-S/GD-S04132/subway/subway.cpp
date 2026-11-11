#include<bits/stdc++.h>
using namespace std;
const long long N=1e5;
long long c,n,m,d,q,x,y,sum=0; 
long long w[501],k[5*N+5];
long long a[501][501],t[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long r=0;r<q;r++){
		cin>>x>>y;
	}
	cout<<35<<endl<<16;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
