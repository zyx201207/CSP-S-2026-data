#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int cnt[N];
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					i=j;
					memset(cnt,0,sizeof(cnt));
					cnt[a[j]]++;
					j++;
				}else{
					cnt[a[j]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
