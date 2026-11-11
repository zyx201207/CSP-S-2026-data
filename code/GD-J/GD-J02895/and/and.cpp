#include<bits/stdc++.h>
using namespace std;
const int kkk=2e5+5;
int n,m,a[kkk],ans,b,c,k[100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b=max(b,a[i]);
	}
	c=a[1],ans=a[1]&a[2];
	for(int i=1;i<=n;i++)c&=a[i];
	if(n==m){
		printf("%d",c);
		return 0;
	}
	if(m==1){
		printf("%d",b);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(b<=20){
		for(int i=1;i<=n;i++)k[a[i]]++;
		for(int i=20;i>=1;i--){
			if(k[i]>=m){
				printf("%d",i);
				return 0;
			}
		}
		if(k[4]+k[1]>=m){
			printf("4");
			return 0;
		}
		if(k[4]+k[2]+k[1]>=m){
			printf("2");
			return 0;
		}
		else{printf("1");
		return 0;
		}
	}
	printf("1");
	return 0;
}
