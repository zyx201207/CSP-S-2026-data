#include <bits/stdc++.h>
using namespace std;

long long n,a,len,ans;
char c;
string s,s_or;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n); 
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a,&c);
		if(a>=100000000){
			printf("0");
			return 0;
		} 
		len+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	s_or=s;
	reverse(s.begin(),s.end());
	if(s_or==s){
		printf("0");
		return 0;
	}
	for(int i=0;i<ceil((double)len/2);i++){
		if(s_or[i] != s[i]) ans++;
	}
	printf("%lld",ans);
	
	return 0;
} 
