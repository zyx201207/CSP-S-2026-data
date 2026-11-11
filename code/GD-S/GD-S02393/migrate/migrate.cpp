#include<bits/stdc++.h>
using namespace std;
int b[2000005][2];int t,k;int n,m;int a[2000005];
void f(int x,int y,int z){
	if(a[x]-a[z]>=3){
		if(y<b[x][1]){
			b[x][1]=y;
			b[x][0]=1;
		}else if(y==b[x][1]){
			b[x][0]++;
		}
	}
	if(x>=t){
		return;
	}
    for(int i=1;i<=k;i++){
    	for(int j=1;j<=k;j++)
    	if(x+i<=t and a[x]+i>=a[x+j]-a[x]){		
    	f(x+j,y+1,z);
		}else{
			break;
		}	
}
}
int main(){
	for(int i=1;i<=2000004;i++){
		b[i][1]=2000004;
	}
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>t>>k;
		
		for(int j=1;j<=t;j++){
			cin>>a[j];
		}
		int ans=0;
		for(int j=1;j<t-2;j++){
		    f(j,0,j);
			for(int l=j+3;l<=t;l++){
				if(b[l][0]==2){
					ans++;
				}
				b[l][0]=0;
				b[l][1]=2000005;
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
