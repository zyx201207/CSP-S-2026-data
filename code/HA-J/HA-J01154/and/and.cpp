#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	long long z=0;
	if(m==1){
		for(int i=1;i<=n;i++) if(a[i]>z) z=a[i];
		
	}
	else if(m==n){
		z=a[1];
		for(int i=2;i<=n;i++) z=z&a[i];
	}
	else{
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum=a[i];
			for(int j=i+1;j<=(i+m-1);j++){
				sum=sum&a[j];
			}
			if(sum>z) z=sum;
		}
	}
	printf("%lld",z);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
