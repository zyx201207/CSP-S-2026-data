#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,b[200004],x[200004],w[6000][6000],mw[200004],sum[200006];
void sus(int y){
	sum[1]=1;
	if(b[y]==2){
		for(int i=y+1;i<=n;i++){
			if(w[y][i]==mw[y]){
				sum[i]=2*sum[y];
			}
		}
	}
	else{
		for(int i=y+1;i<=n;i++){
			if(w[y][i]==mw[y]){
				sum[i]=sum[y];
			}
		}
	}
	if(y==n){
		return;
	}
	sus(y+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			w[i-1][i]=x[i]-x[i-1];
			b[i-1]++;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(x[i]-x[j]<=d){
					w[j][i]=x[i]-x[j];
				}
				if(w[j][i]<mw[j]&&w[j][i]!=0){
					mw[j]=w[j][i];
					b[j]=1;
				}
				else if(w[j][i]==mw[j]&&w[j][i]!=0){
					b[j]+=1;
				}
			}
		}
		sus(1);
		cout<<sum[n];
		memset(w,0,sizeof(w));
		memset(mw,0,sizeof(mw));
		memset(b,0,sizeof(b));
		memset(sum,0,sizeof(sum));
	}
	
	return 0;
} 
