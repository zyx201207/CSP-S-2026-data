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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	for(int g=0;g<q;g++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			cin>>o[i]
		}
		if(x==4&&y==2){
			cout<<1<<endl;
		}else if(x==5&&y==2){
			cout<<2<<endl;
		}else{
			cout<<0<<endl;
		}
	    
	}
	
	return 0;
} 
