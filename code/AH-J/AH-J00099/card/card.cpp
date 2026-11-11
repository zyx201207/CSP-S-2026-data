#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
int c[500010];
bool f[500010];
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
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		long long r=i,l=i;
		while(l<=n){
			c[a[l]]++;
			if(c[a[l]]>1){
				for(int k=r;k<=l;k++){
					if(a[k]==a[l]&&f[k]!=1){
						for(int z=k;z<l;z++){
							f[z]=1;
						}
						break;
					}
				}
			}
			l++;
		}
		memset(c,0,sizeof(c));
		for(int j=r;j<=l-1;j++){
			if(a[j]<=m&&c[a[j]]!=1&&f[j]!=1){
				b[a[j]]++;
				c[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
