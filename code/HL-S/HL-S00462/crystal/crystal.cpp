#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=1;
	scanf("%d %d",&n,&m);
	int a[n+10],b[n+10];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			if(a[j]-a[k]>=0){
				if (n-(a[j]-a[k])==0) sum=2;
				if (n-(a[j]-a[k])-(a[k]-a[k-1])==0) sum=3;
			}
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}