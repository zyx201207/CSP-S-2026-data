#include<bits/stdc++.h>
using namespace std;
int a[505][505],t[505][505],ans,v[5000005];
int c,n,m,d,q,w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int e=0;
	while(n--){
	   int x;e++;
	   cin>>x;
	   v[e]=x;
	   for(int i=1;i<=x;i++){
	   	 cin>>a[e][i]>>t[e][i];
	   }		
	}
	while(q--){
		int r,l;
		cin>>r>>l;
        int x,y;
		for(int i=1;i<=e;i++){
			 int p=0;
			for(int j=1;j<=v[i];j++){
				if(a[i][j]==r){
				  p++;x=j;
				}
				if(a[i][j]==l){
				  p++;y=j;
				}
			}
	  if(p==2) ans=ans+w[a[i][x]]+t[i][x]+w[a[i][y]]+t[i][y];
		}		
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
