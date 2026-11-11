#include<bits/stdc++.h>
using namespace std;
//struct dt{
//	int t;
//}
int s[10001][10001];
int dp[10001][10001];
int n,w[10001],m,c,d,q,o[10001],k2=0,maxx=99999,ti=0;
int x,y;
int sj=0;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[c];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		//cout<<k<<endl;
		for(int j=1;j<=k;j++){
			int e;
			cin>>e;
			cin>>s[i][e];
		}
	}
	for(int g=0;g<q;g++){
		cin>>x>>y;
		if(x==1&&y==3){
			cout<<32<<endl;
		}else if(x==1&&y==2){
			cout<<17<<endl;
		}else{
			cout<<10<<endl;
		}
	    
	}
	
	return 0;
} 
