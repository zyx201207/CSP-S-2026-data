#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],x[N],y[N],c[N][N];
long long n,m,cmax=0,amax=0,p=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[0][i]=a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			c[i][j]=c[0][j]+i;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			x[c[i][j]]++;
			y[c[i][j]]+=i; 
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(x[c[i][j]]>amax){
				if(y[c[i][j]]<=m){
					amax=x[c[i][j]];
					cmax=x[c[i][j]];
				}
				else{
					x[c[i][j]]=-N;
				}
			}
		}
	}
	cout<<cmax;
	return 0;
}
