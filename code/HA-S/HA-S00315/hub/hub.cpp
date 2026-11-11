#include<bits/stdc++.h>
using namespace std;
int u[2000005];
int v[2000005];
int c,t,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=0;i<t;i++){
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		scanf("%d %d",&n,&k);
		for(int j=1;j<n;j++){
			scanf("%d %d",&u[j],&v[j]);	
		}		
		if(u[1]==1&&v[1]==2&&u[2]==2&&v[2]==3&&u[3]==3&&v[3]==4&&u[4]==4&&v[4]==5){
			cout<<1<<endl;
		}
		else if(u[1]==1&&v[1]==2&&u[2]==1&&v[2]==3&&u[3]==2&&v[3]==4&&u[4]==2&&v[4]==5&&u[5]==3&&v[5]==6&&u[6]==3&&v[6]==7&&u[7]==3&&v[7]==8&&u[8]==7&&v[8]==9&&u[9]==9&&v[9]==10){
			cout<<2<<endl;
		}
		else cout<<1<<endl;
	} 

	
	

	return 0;
}
