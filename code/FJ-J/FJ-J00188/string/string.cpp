#include<bits/stdc++.h>
using namespace std;
char c;
string s;
long long n,a,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}long long r=s.size()-1;
	for(long long l=0;l<r;l++){
		if(s[l]!=s[r])ans++;
		r--;	
	}cout<<ans;
	
	return 0;
}
