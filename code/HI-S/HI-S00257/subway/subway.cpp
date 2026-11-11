#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[505][2005];
int w[500005];
ll ans=INT_MAX;
int xx,yy;
int c,n,m,d,q;
void fun(int x,int y,int sum){

	if(y==yy){
		ans=min(ans,sum+a[x][y]);
		return ;
	}
	sum+=a[x][y];
	
	int num=a[x][y];
	a[x][y]=0;

 		for(int i=1;i<=m;i++){
 			if(a[x][i]!=0) fun(x,i,sum);
		 }
 	    if(a[x-1][y]!=0) fun(x-1,y,sum);
 	    if(a[x+1][y]!=0) fun(x+1,y,sum);
 	    

 	 a[x][y]=num;
	
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	int k;
	cin>>k;
	for(int j=1;j<=k;j++){
		int x,y;
		cin>>x>>y;
	
		a[i][x]=y;
	}
	
}

while(q--){
	int x,y;
	cin>>x>>y;
	xx=x;
	yy=y;
	if(m<=2000){
	
	long long ma=INT_MAX;
    for(int i=1;i<=n;i++){
    	if(a[i][x]!=0){
    		ans=INT_MAX;
    		fun(i,x,0);
		}
		ma=min(ans,ma);
	}
	
	cout<<ma+w[xx]+w[yy]<<endl;
}else{
	ll t;
	for(int i=1;i<=m;i++){
		if(a[1][i]!=0){
		t=a[1][i];	
		}
	}
	cout<<w[xx]+w[yy]+t<<endl;
}
	
}

	return 0;
}

