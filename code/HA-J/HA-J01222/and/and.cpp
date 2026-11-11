#include <bits/stdc++.h>
using namespace std;
int a[200100],b[200010]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int maxn=-1;
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>maxn&&a[i]!=a[j]){
					maxn=a[i]&a[j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]==maxn&&a[i]!=a[j]){
					b[i]=1;
					b[j]=1;
				}
			}
		}
	while(m-1){
		for(int i=1;i<=n;i++){
			if(maxn&a[i]>maxn&&b[i]==0){
				maxn=maxn&a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(maxn&a[i]==maxn&&b[i]==0){
				b[i]=1;
			}
		}
		m--;
	}
	printf("%d",maxn);
	return 0;
}
