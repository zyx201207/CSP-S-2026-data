#include<bits/stdc++.h>
using namespace std;
long long n,m,q,d,c,k[510],w[510],a[510][20010],t[500][20010],x,y,p,l,h,u,g,sum,f3[20010];
bool f,f1,f2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f3[a[i][j]]++;
		}
	}
	for(int o=1;o<=q;o++){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			f2=0,f1=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					p=i;
					l=j;
					f=1;
					f2=1;
				}
				if(f2==1&&a[i][j]==y){
					cout<<w[x]+t[p][l]+t[i][j]+w[y];
					f1=1;
					break;
				}
			}
			if(f1==1){
				break;
			}
		}
		if(f==1&&f1==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==y){
						f1=1;
						u=i;
						h=j;
						break;
					}
				}
				if(f1==1){
					break;
				}
			}
			for(int i=1;i<=m;i++){
				if(f3[i]>1){
					for(int v=1;v<=n;v++){
						for(int j=1;j<=k[i];j++){
							if(a[v][j]==i){
								sum+=t[v][j];
							}
						}
					}
					cout<<w[x]+w[y]+t[p][l]+t[u][h]+sum;
					break;
				}
			}
		}
	}
	return 0;
}

