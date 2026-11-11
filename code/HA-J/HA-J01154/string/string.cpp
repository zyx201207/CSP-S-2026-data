#include<bits/stdc++.h>
using namespace std;
long long n,x,ans=0,sum=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %c",&x,&c);
		ans=ans+x;
		for(long long i=0;i<x;i++) s+=c;
	}
	
	for(long long i=0;i<(ans/2);i++){
		if(s[i]!=s[ans-i-1]) sum++;
	}
	printf("%lld",sum);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
