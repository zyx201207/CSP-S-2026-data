#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[50005];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int d=a[2]-a[1];
	int x=m/d;
	for(int i=sqrt(2*x)-100;i<=sqrt(2*x)+100;i++){
		if(i<0)	continue;
		if(i*(i+1)/2<=x&& (i+1)*(i+2)/2>x){
			if(m/(i*(i+1)/2)==d || (i==1&&m>=d)){
				printf("%d",i+1);
			}
			else printf("%d",i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
