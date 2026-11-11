#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
int n,m,a[N],ans,anb;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",a[n]);
		return 0;
	}
	if(m==n){
		anb=a[1];
		for(int i=2;i<=n;i++){
			anb&=a[i];
		}
		printf("%d",anb);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1) anb=a[2];
			else anb=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i) anb&=a[j];
			}
			ans=max(ans,anb);
		}
	}
	printf("%d",ans);
	return 0;
}
