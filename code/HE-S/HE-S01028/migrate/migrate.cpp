#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,x;
	long long d;
	scanf("%d%d",&c,&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&n,&d);
		for(int k=0;k<n;k++){
			scanf("%d",&a[k]);
		}
		x=0;
		int sum=0,l=0;
		for(int j=0;j<n;j++){
			for(int k=l;k<j;k++){
				x+=a[k+1]-a[k];
			}
			x%=d;
			if(x!=0)sum++;
		}
		l++;
		printf("%d",sum);
	}
	return 0;
}
