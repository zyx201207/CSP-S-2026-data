#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char s[5],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%s",&a[i],s);
		c[i]=s[0];
	}
	int l=1,posl=1,r=n,posr=a[n];
	long long ans=0;
	while (l<r){
		if (a[l]-posl+1==posr){
			if (c[l]!=c[r]) ans+=posr;
			l++,posl=1,posr=a[--r];
		}else if (a[l]-posl+1>posr){
			if (c[l]!=c[r]) ans+=posr;
			posl+=posr,posr=a[--r];
		}else{
			if (c[l]!=c[r]) ans+=a[l]-posl+1;
			posr-=a[l]-posl+1,posl=1,l++;
		}
	}
	printf("%lld",ans);
	return 0;
} 
