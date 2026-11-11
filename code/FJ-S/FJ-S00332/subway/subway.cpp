#include<bits/stdc++.h>
using namespace std;
const int MAXN=500;
const int MAXM=500010;//k
int c,n,m,d,q;
int w[MAXM],away[MAXN][MAXM];//line to station
int subway[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a,t;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			away[i][a]=t;
		}
	}
	for(int i=1;i<=n;i++){
		subway[i][i]=0;
		for(int j=1+i;j<=n;j++){
			subway[i][j]=0x0fffffff;
			for(int k=1;k<m;k++){
				if(away[i][k]&&away[j][k]){
					subway[i][j]=min(subway[i][j],away[i][k]+away[j][k]);
				}
			}
			
			subway[j][i]=subway[i][j];
			
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" , "<<j<<" : "<<subway[i][j]<<endl;
		}
	}
	*/
	
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				subway[i][j]=min(subway[i][j],subway[i][k]+subway[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>a>>t;
		int ans=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(!away[j][a]){
				continue;
			}
			for(int k=1;k<=n;k++){
				if(!away[k][t]){
					continue;
				}
				//
				
				ans=min(ans,away[j][a]+subway[k][j]+away[k][t]);
				
				//
			}
		}
		cout<<ans+w[a]+w[t];//<<endl;
	}
	/*for(int i=1;i<=m;i++){
		for(int j=head[i];j!=0;j=nxt[j]){
			cout<<station[j]<<" ";
		}
		cout<<endl;
	}*/
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
