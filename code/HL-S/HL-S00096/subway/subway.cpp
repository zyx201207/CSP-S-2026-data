#include<bits/stdc++.h>
using namespace std;
const int N=5e4+1;
int c,n,m,d,q;
int w[N],k[N];
int a[501][N],t[501][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int z=1;z<=q;z++){
		int ans=0;
		int x,y,s,e;
		cin>>x>>y;
		int flag=0;
		for(int i=1;i<=n;i++){
			flag=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					flag=1;
					s=i;
					ans+=(t[i][j]+w[a[i][j]]);
				}if(a[i][j]==y && flag){
					ans+=(t[i][j]+w[a[i][j]]);
					cout<<ans;
					flag=2;
					break;
				}if(a[i][j]==y){
					e=i;
				}
			}if(flag==2){
				break;
			}
		}if(flag==2){
			continue;
		}
	}
	return 0;
}
