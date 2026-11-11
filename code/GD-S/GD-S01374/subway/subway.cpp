#include<bits/stdc++.h>
using namespace std;
int n,ans,m,r,x,cc,y,k,a[1005][1005],z[1005],c[1005][1005],d,q,mi=INT_MAX;
void f(int v,int xx){
	if(v==y){
		for(int i=2;i<=2*a[xx][1];i+=2){
			if(a[xx][i]==v){
				ans=a[xx][i+1];
				return ;
			}
		}
	}
	for(int i=1;i<=2*c[v][0]-1;i+=2){
		if(c[v][i]>v){
			f(c[v][i],c[v][i+1]);
			if(ans!=0){
				for(int k=2;k<=2*a[xx][1];k+=2){
					if(a[xx][k]==v){
						ans+=a[xx][k+1];
						break;
					}
				}
				int kk=c[v][i+1];
				for(int k=2;k<=2*a[kk][1];k+=2){
					if(a[kk][k]==v){
						ans+=a[kk][k+1];
						break;
					}
				}
				if(xx!=0)return ;
				else mi=min(mi,z[x]+z[y]+ans),ans=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&z[i]);
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		for(int j=2;j<=2*a[i][1]+1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=2*a[i][1];j+=2){
			for(int k=2;k<=2*a[i][1];k+=2){
				if(j!=k)c[a[i][j]][++c[a[i][j]][0]]=a[i][k],c[a[i][j]][++c[a[i][j]][0]]=i;
			}
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		f(x,0);
		cout<<mi<<endl;
	} 
	return 0; 
} 
