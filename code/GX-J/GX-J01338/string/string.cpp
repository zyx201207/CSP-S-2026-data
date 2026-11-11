#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[300000],f[30000][30000]{0},s=0;
	string b,c;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i]>>b[i];//cout<<b[i];}
	if(n==1)cout<<0;
	else{for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)c[s++]=b[i];
		cout<<c[s];}cout<<'\n';
		for(int l=1;l<=s;l++){
			for(int i=1;i+l<=s;i++){int j=i+l;
				f[i][j]=1e9;
				f[i][j]=min(f[i+1][j]+1,f[i][j-1]+1);
				if(c[i]==c[j]){if(l>1)f[i][j]=f[i+1][j-1];
				else f[i][j]=0;}
				}
			}cout<<f[1][s]-1;
			}
	return 0;
	
}
