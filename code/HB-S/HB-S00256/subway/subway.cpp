#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,b,e,sum=0,ans=1000000000;
int g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int k[n+1];
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	int a[1000000][n+1];
	for(int i=1;i<=n;i++){
		cin>>g;
		for(int j=0;j<g;j++){
			int x;
			cin>>x;
			cin>>a[x][i];
		}
	}
	while(cin>>b>>e){
		sum=sum+k[b]+k[e];
		for(int i=1;i<=n;i++){
			if(a[i][1]&&a[i][2]){
				sum=a[i][1]+a[i][2]+a[b][1]+a[e][2];
			}
			else if(a[i][1]&&a[i][3]){
				sum=a[i][1]+a[i][3]+a[b][1]+a[e][3];
			}
			else if(a[i][2]&&a[i][3]){
				sum=a[i][2]+a[i][3]+a[b][2]+a[e][3];
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
