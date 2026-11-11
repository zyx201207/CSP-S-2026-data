#include<bits/stdc++.h>
using namespace std;

string s;char c;long long n,a,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s=s+c;
	}
	 long long r=s.size()-1;
	for(long long i=0;i<=r/2;i++){
		if(s[i]!=s[r-i])ans++;
	}
	cout<<ans;
	
	return 0;
}
