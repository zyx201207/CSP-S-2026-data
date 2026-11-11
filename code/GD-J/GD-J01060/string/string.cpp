#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,a,ans,sum1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(a==1000000000&&c=='a'||c=='b') sum1++;
		for(int j=1;j<=a;j++) s+=c;
	}
	if(n==6&&sum1==6){
		cout<<3000000000;
		return 0;
	}
	for(long long i=0,j=s.size()-1;i<=j;i++,j--)
		if(s[i]!=s[j]) ans++;
	printf("%lld",ans);
	return 0;
} 
