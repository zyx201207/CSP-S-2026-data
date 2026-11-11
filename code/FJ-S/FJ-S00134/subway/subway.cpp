#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct sub{
	int a;
	int t;
}subs[505][500005];
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
			cin>>a[i][k].a>>a[i][k].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=1;j++){
			for(int k=1;k<=1;k++){
				int l=1;
				while(sub[j][l]){
					if(sub[j][l].a==x){
						int p=1;
						while(sub[j][p]){
							if(sub[j][p])
						}
					}
				}
			}
		}
	}
	
	
	return 0;	
} 
