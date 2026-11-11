#include<bits/stdc++.h>
using namespace std;
long long n,ans,a1;
string s;
char c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a1>>c1;
		for(long long j=1;j<=a1;j++){
			s+=c1;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s[i])ans++;
	}
	cout<<ans/2;
	return 0;
}
