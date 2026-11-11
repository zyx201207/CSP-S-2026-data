#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=1;i<=a;i++)s+=c;
	}
	string t=s;
	reverse(s.begin(),s.end());
	long long ans=0;
	for(int i=0;i<s.size();i++)if(s[i]!=t[i])ans++;
	cout<<ans/2;
	return 0;
}
