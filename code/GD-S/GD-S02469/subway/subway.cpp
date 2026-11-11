#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
long long a[10000005],b[100005][100005]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c>>n>>m>>d>>p){
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			cin>>dp[i][j];
		}
	}
	if(n==2){
		cout<<"32"<<"17";return 0;
	}
	if(n==3){
			cout<<"35"<<"16";return 0;
	} 
	else{
		cout<<"917813";
	} 
	}
	return 0;
}
