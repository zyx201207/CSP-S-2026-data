#include<bits/stdc++.h>
using namespace std;
int c,t,n,kk,ans=1111111,r[100][100],w[100];
void build(int x,int fa,int l){
	for(int i=1;i<=n;i++){
		if(i==x || i==fa) continue;
		if(r[x][i] && w[i]>l){
			w[i]=l;
			build(i,x,l+1);
		}
	}
}
int find(){
	int mx=0;
	for(int i=1;i<=n;i++){
		if(w[i]>mx) mx=w[i];
	}
	return mx;
}
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>kk;
		memset(r,0,sizeof(r));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			r[u][v]=r[v][u]=1;
		}
		if(kk==1) cout<<(n+1)/2-1<<endl;
		else if(kk==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					w[i]=w[j]=0;
					build(i,0,1);
					build(j,0,1);
					ans=min(ans,find());
					for(int p=1;p<=n;p++){
						w[p]=111111;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(kk==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						w[i]=w[j]=w[k]=0;
						build(i,0,1);
						build(j,0,1);
						build(k,0,1);
						ans=min(ans,find());
						for(int p=1;p<=n;p++){
							w[p]=111111;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(kk==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							w[i]=w[j]=w[k]=w[l]=0;
							build(i,0,1);
							build(j,0,1);
							build(k,0,1);
							build(l,0,1);
							ans=min(ans,find());
							for(int p=1;p<=n;p++){
								w[p]=111111;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}

