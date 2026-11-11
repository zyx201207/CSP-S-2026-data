#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
	    scanf("%lld",&a);
	    scanf("%s",&c);
	    for(int j=1;j<=a;j++)
	        s+=c;
	} 
	int cc=s.size();
	long long ans=0;
	for(int i=0;i<cc/2;i++){
		if(s[i]!=s[cc-i-1])
			ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
