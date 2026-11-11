#include <bits/stdc++.h>
using namespace std;
long long n,a,le,su;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		scanf("%s",&c);
		for(int i=1;i<=a;i++){
			s=s+c;
		}
		le+=a;
	}
	
	for(int i=0;i<le;i++){
		if(s[i]!=s[le-i-1] && i<le-i-1){
			su++;
		}
	}
	printf("%lld",su);
	
	return 0;
}
