#include<bits/stdc++.h>
using namespace std;
int n,x[1001],u=1,bz=0,p;
char s[1001];
long double l[10000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int y=1;y<=x[i];y++){
			l[u]=s[i];
			u++;
		}
		p+=x[i];
	}
	u=p;
	p/=2;
	for(int i=1;i<=p;i++){
		if(l[i]!=l[u-i+1]){
			bz++;
		}
	}
	printf("%d",bz);
	return 0;
}
