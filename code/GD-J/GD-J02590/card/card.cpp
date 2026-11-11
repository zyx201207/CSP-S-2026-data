#include<bits/stdc++.h>
using namespace std;
int c[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n=6,m;cin>>n>>m;vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=m;i++){
			cout<<1<<' ';
		}
		return 0;
	}
		vector<int> b(m,0);
		for(int i=1;i<=n;i++){
			
			memset(c,0,sizeof(c));
			c[i]=a[i];
			for(int j=i+1;j<=n;j++){
				c[j]=a[j];
				for(int k=i;k<=j;k++){
					if(c[j]==c[k]){
						for(int x=j;x<=k;x++){
							c[x]=0;
						}
						c[k]=a[k];
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(c[j]){
					b[c[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
	return 0;
}
