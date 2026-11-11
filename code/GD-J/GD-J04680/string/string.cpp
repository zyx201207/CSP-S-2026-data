#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c;
		while(a[i]!=0){
			a[i]--;
			s+=c;
		} 
	}
	long long ans=0;
	for(int l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r])ans++;
	}
	printf("%lld",ans);
	return 0;
}
