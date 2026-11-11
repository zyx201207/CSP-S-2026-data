#include<bits/stdc++.h>
using namespace std;
int n;
long long z=0,r[200005];
char p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>r[i]>>p[i];
	long long x=0,y=0;
	for(int i=1,j=n;i<=j;){
		if(p[i]!=p[j])
		if(r[i]-x>r[j]-y){
			z+=r[j]-y;
			x+=r[j]-y;
			y=0;j--;
		}else if(r[i]-x==r[j]-y){
			z+=r[j]-y;
			i++;j--;
			x=0;y=0;
		}else{
			z+=r[i]-x;
			y+=r[i]-x;
			x=0;i++;
		}
		else{i++;j--;}
	}
	printf("%lld",z);
	fclose(stdin);fclose(stdout);
	return 0;
}
