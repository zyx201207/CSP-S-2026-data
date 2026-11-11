#include<bits/stdc++.h>
using namespace std;
long long n,x,ans,m,s,le,re,b[300005],nn,f,ree;
char a[300005];
string o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);cin>>a[i];
		while(x){
			o=o+a[i];
			x--;
		}
	}
	for(int i=0;i<o.size()/2;i++){
		if(o[i]!=o[o.size()-i-1])ans++;
	}
	printf("%lld",ans);
	return 0;
}
