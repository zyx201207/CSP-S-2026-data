#include<bits/stdc++.h>
using namespace std;
int c,t;
int u[1000006][2];
int lus[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		int luss[1000006]={0};
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[j][0]>>u[j][1];
		}
		for(int j=1;j<=n;j++){
			for(int k=2;k<=n;k++){
				if(u[k][0]<u[k-1][0]){
					int x=u[k][0],y=u[k][1];
					u[k][0]=u[k-1][0];
					u[k][1]=u[k-1][1];
					u[k-1][0]=x;
					u[k-1][1]=y;
				}
			}
		}
		int len=0;
		int wei;
		lus[1]=1;
		for(int j=1;j<=n;j++){
			lus[u[j][1]]=lus[u[j][0]]+1;
		}
		for(int j=1;j<=n;j++){
			len=max(len,lus[j]);
		}
		for(int j=1;j<=n;j++){
			if(lus[j]==len){
				wei=j;
			}
		}
		for(int j=n;j>=1;j--){
			luss[u[j][0]]=max(luss[u[j][1]]+1,luss[u[j][0]]);
		}
		int leng=0;
		for(int j=1;j<=n;j++){
			//cout<<luss[j]<<" ";
			if(u[j][0]==1)leng+=luss[u[j][1]]+1;
		}
		//cout<<endl;
		//cout<<leng+1<<" "<<k<<endl;
		cout<<ceil((leng+1-k)/3.0)<<endl;
	}
	return 0;	
} 
