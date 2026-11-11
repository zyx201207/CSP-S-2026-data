#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
int time[550];
int pain[105][105];
int dp[550[505];  
int haoshi[550][550];
int main(){
	//GZ-S00318,安顺市第一高级中学，朱兴旺 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	}
	for(int i=1;i<=m;i++){
		cin>>time[i];
	}
	for(int i0=1;i0<=n;i0++){
		int k;
        cin>>k;
    	   while(k--){
    		    for(int i=1;i<=m;i++){
    			    for(int j=1;j<=m;j++){
    				    cin>>haoshi[i][j];
				}
			}
		}
	} 	
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q,j++){
			cin>>pain[i][j];
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
		    if(dp[i][j]<=pian[i][j]) {
		    	dp[i][j]+=dp[i+1][j+1];
			}
		}
	}
	cout<<dp[m][m]<<'\n';
	fcolse(stdin);
	fclose(stdout);
	return 0;
}
