#include<bits/stdc++.h>
using namespace std;
string s,ch;
char c[200005];
long long ans=0,n,a[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf("%s",&c[i]); 
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long lens=s.size();
	long long j=lens-1;
	
	for(long long i=0;i<lens;i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	ans/=2;
	printf("%lld",ans);
	return 0;
} 
