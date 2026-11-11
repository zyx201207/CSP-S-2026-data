#include<bits/stdc++.h>
#define var long long
using namespace std;
const var N = 300+10;
var c,T,n,x[N],d;
bool f[N],g[N];
var dis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(var i=1;i<=n;i++) cin>>x[i];
		var ans=0;
		for(var v=1;v<=n;v++){
			memset(f,0,sizeof f); memset(g,0,sizeof g); memset(dis,0,sizeof dis);
			f[v]=1;
			for(var u=v+1,l=v;u<=n;u++){
				while(x[u]-x[l]>d&&l<=u-1) l++;
				
				dis[u]=(dis[l]+1);
				
				var op1=0,op2=0;
				for(var k=l;k<u;k++) op1+=((dis[k]+1)==dis[u]&&f[k]),op2+=((dis[k]+1)==dis[u]&&g[k]);
				
				if(op1==1&&op2==0) f[u]=1;			
				if((op1==2)+(op2==1)==1) g[u]=1;
				
				if(g[u]) ans++;
				//cerr<<g[u]<<" ";
			}
			//cerr<<endl;
		}
		cout<<(ans)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
