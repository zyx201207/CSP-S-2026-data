#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,al[200001],i,j,a,b,summ;
char cl[200001];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (i=1;i<=n;++i) {
		scanf("%lld%s",&al[i],&cl[i]);
		j+=al[i];
	}
	i=0;a=1;b=n;n=min(al[a],al[b]);
	while (i+n<=j-n&&a<b) {
		i+=n;j-=n;
		if (cl[a]!=cl[b]) summ+=n;
		al[a]-=n;al[b]-=n;
		if (al[a]==0) ++a;
		if (al[b]==0) --b;
		n=min(al[a],al[b]);
	}
	printf("%lld",summ);
	return 0;
}
