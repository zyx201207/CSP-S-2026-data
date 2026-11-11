#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[500001];
int p[200001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			memset(p,0,sizeof p);
			for(int k=j;k<=n;k++){
				if(p[a[k]]){
					for(int l=p[a[k]];l<k;l++){
						p[a[l]]=0;
					}
				}p[a[k]]=k;
			}ans+=(bool)(p[a[j]]);
		}printf("%d ",ans);
	}
}