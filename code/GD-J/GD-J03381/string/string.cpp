#include<bits/stdc++.h>
using namespace std;
string w,s;
long long n,x,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&x);
		cin>>w;
		for(long long j=1; j<=x; j++){
			s=s+w;
		}
	}
	for(int i=0; i<s.size()/2; i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
} 
