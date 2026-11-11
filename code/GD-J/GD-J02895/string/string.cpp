#include<bits/stdc++.h>
using namespace std;
const int kkk=2e5+5;
int n,a[kkk],big,ans,m1=1,a1,a2;
char b[kkk];
long long q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int ina;
		char inb;
		scanf("%d%c%c",&ina,&inb,&inb);
		if(inb==b[m1-1])a[m1-1]+=ina,m1--;
		else a[m1]=ina,b[m1]=inb;
		m1++;
	}
	n=m1-1,m1=1;
	for(int i=1;i<=n;i++)q+=a[i];
	for(int i=1;i<=q/2;i++){
		if(i-a1>a[m1])a1+=a[m1],m1++;
		if(i-a2>a[n])a2+=a[n],n--;
		if(b[m1]!=b[n])ans++;
	}
	printf("%d",ans);
	return 0;
}
