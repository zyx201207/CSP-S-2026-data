#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int c,n,m,d,p,q,k,x,y,ans,b;


struct sub{
	int a,t;
} ma[510][MAXN],w[MAXN][510];

bool go[MAXN][510];
int all,dc=1;

int road[MAXN],dp[MAXN][100010];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++){
		//input wi~m
		cin>>w[i][0].t;
	}
	for(int i=1;i<=n;i++){
		//input ki~n
		int g=1;
		cin>>ma[i][0].a;
		for(int j=1;j<=ma[i][0].a>>1;j++)
		{
			//input a,t
			cin>>ma[i][j].a>>ma[i][j].t;
			w[ma[i][0].a][g].a=ma[i][j].a;
			w[ma[i][0].a][g].t=j;
			g++;
			all++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		//input from to
		cin>>x>>y;
		ans+=w[x][0].t+w[y][0].t;
		
		int da,db,dl,stp=0;
		
		menset(go,go*MAXN+510,0);
	

		while(/** finish line**/ stp==all){
			da=x;
		for(int i=1;w[da][i+1].a==0;i++){
			//to change line
			if(go[da][i]!=0){
				dp[da][dc]+=min(ma[i][w[da][i].t].t,dp[da][i]);
				go[da][i]=1;
				stp++;
			}
		}	
		for(int j=1;j<=ma[da][0].a;j++){
			//to go
			if(go[i][da[ma[da][i].a]]!=0){
				dp[1][da[ma[da][i].a]]+=min(ma[i][w[da][i].t].t,dp[da][i]);
				go[da][i]=1;
				stp++;
			}
			
		}
		}
	
	
	cout<<dp[i][y]+ans;
	}
	return 0;
} 

//Ã»Ð´Íê 
