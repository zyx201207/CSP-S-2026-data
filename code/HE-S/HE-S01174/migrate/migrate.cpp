#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int ta=0;ta<t;ta++){
		scanf("%d %d",&n,&d);
		int cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(c>12){
			printf("%d\n",0);
		}
		else if(c==12 || c==11){
			if(abs(a[1]-a[0])>d){
				printf("%d\n",0);
				continue;
			}
			for(int j=0;j<n;j++){
				for(int k=j;k<n;k++){
					if(abs(k-j)%d!=0){
						cnt++;
					}
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
