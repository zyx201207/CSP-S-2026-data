#include<bits/stdc++.h>
using namespace std;
long long n,ans,a;
char w;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>w;
		for(long long j=1;j<=a;j++){
			s+=w;	
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
