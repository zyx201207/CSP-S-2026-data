#include<bits/stdc++.h>
using namespace std;
int n,a[200005],t,num;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++){
		scanf("%d",&a[i]);
		scanf("%c",&c[i]);
	}
	for(int i=2;i<n;i+=2){
		if(c[i]!=c[i+1]) t=1;
	}
	if(t!=1){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		num+=a[i];
	if(num%2==0) printf("%d",num/2);
	else printf("%d",(num-1)/2);
	return 0;
}
