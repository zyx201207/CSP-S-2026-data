#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int k=j-1;k>=i;k--){
					if(c[k]==-1){
						continue;
					}
					if(a[k]!=a[j]){
						b[a[k]]=0;
						c[k]=-1;
					}else{
						break;
					}
				}
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				d[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
