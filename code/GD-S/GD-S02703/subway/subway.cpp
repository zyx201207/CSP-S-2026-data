#include<bits/stdc++.h>
using namespace std;
int n,m,x,k,a[1000][1000],p[1000],t[1000][1000],c[1000],x2,y,t1,s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	 
	cin>>s>>n>>m>>x>>t1;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
		cin>>a[i][j]>>t[i][j];
		c[a[i][j]]=t[i][j];
		}
	}
	
	if(n==1){
		for(int i=1;i<=t1;i++){	
			cin>>x2>>y;
			cout<<p[x2]+c[x2]+p[y]+c[y]<<endl;			
		}	
	}

	return 0;
} 
