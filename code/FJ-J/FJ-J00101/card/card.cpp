#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=5e5+5;

int n,m,a[MAXN],now[MAXN],len,ans[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=len;k++){
				if(now[k]==a[j]){
					len=k-1;
					break;
				}
			}
			now[++len]=a[j];
		} 
		for(int j=1;j<=len;j++){
			ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
