#include<bits/stdc++.h>
using namespace std;
long long t,m;
long long f[4005],a[4005][4005];
void fa(int x){
	if(f[x]!=x){
		f[x]=f[f[x]];
		
		return fa(f[f[x]]);
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>m;
	while(m--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
			f[x]=y;
			f[y]=x;
		}
		for(int i=1;i<=n;i++){
			if(f[i]!=i){
				fa(f[i]);
			}
		}
		int c=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i]==f[j]){
					if(f[i]==j||f[j]==i){
						c=1;
					}else{
						c=2;
					}
					
				}else{
					c=3;
				}
			}
		}
		cout<<c<<'\n';
	} 
	return 0;
} 
