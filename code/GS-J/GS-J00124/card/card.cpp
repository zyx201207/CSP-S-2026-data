#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
bool f[N];
int h;
int p[N],g[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		h=0;
		memset(f,0,sizeof f);
		memset(p,0,sizeof p);
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				p[++h]=a[j];
				f[a[j]]=1;
				g[a[j]]=h;
				
			}else{
				
				for(int l=g[a[j]]+1;l<=h;l++){
					f[p[l]]=0;
				}
				h=g[a[j]];
			}
		}
		for(int k=1;k<=h;k++){
			c[p[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
