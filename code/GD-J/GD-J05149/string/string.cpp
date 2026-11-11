#include<bits/stdc++.h>
using namespace std;
long long n,addd=0,ans=0;
char k1;
long long k2;
vector<int>s;
int main(){
	s.push_back(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&k2,&k1);
		addd+=k2; 
		for(long long j=0;j<k2;j++){
			s.push_back(k1);
		}
	}
	for(long long j=n,i=1;i<addd/2+1;i++,j--){
		if(s[i]!=s[j])ans++;
		cout<<s[i]<<s[j]<<" ";
	}printf("%lld",ans);
}
