#include<bits/stdc++.h>
using namespace std;
string s;
long long ans;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		string a;
		cin>>k>>a;
		for(int j=1;j<=k;j++)s+=a;
	}
	for(long long i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
