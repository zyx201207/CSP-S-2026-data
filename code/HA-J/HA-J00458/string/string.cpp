#include<bits/stdc++.h>
using namespace std;
string s;
int n,l,a[200010];
long long t;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %c",&a[i],&c[i]);
		for(int j=1;j<=a[i];++j)
			s+=c[i];
	}
	l=s.size()-1;
	for(int i=0,j=l;i<j;++i,--j)
		t+=(s[i]!=s[j]);
	printf("%lld\n",t);
	return 0;
}
