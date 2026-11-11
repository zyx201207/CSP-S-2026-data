#include<bits/stdc++.h>
using namespace std;
int w[2000000];
int a[2000000][510];
int t[2000000][510];
int sd[2000000];
int ed[2000000];
int dp[2000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)cin>>sd[i]>>ed[i];
	for(int i=1;i<=q;i++){
	int s=w[sd[i]]+w[ed[i]];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				
			}
		}
		
	cout<<s<<endl;
	}return 0;
} 
