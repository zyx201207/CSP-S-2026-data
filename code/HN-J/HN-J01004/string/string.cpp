#include<bits/stdc++.h>
using namespace std;
long long ans,a[200010],n,js;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		for(long long i=1;i<=a[i];i++){
			s[js]=c[js];
			js++;
		}
	}
	if(s.size()%2==1)
	for(long long i=0,j=js;i<js/2;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	else 
	for(long long i=0,j=js;i<js/2+1;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
