#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,ans,T,z;
int dp[10007],w[100007],k[10007],a[10007][10007],t[10007][10007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
			T=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		ans+=2*T;
		dp[y]=1;
//		while(1){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=k[j];p++){//第j条线的第p站。 
				if(a[j][p]==y){
				ans+=t[j][p];
			}
			for(int p=1;p<=k[j];p++){//第j条线的第p站。 
				if(a[j][p]==x){
				ans+=t[j][p];
			}
	}
//					for(int g=1;g<=k[j];g++){
//						if(a[j][g]==x){
//							ans+=(T)*2*dp[];
//							break;
//						}
//						else{
//							if(!dp[a[j][g]])
//							dp[]
//						}
//					} 
//				}
//			}
//		}
	cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	}
	return 0;
}
//	cout<<ans;
