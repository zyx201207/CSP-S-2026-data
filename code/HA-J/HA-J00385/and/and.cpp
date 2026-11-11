#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[1000005],f[1000005][1000005];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(a[i],(f[i-1][j-1]&a[i]));
			if(i==1||j==1){
				f[i][j]=a[i];
			}
		}
	}
	 
	cout<<f[n][m];
	return 0;	
}
