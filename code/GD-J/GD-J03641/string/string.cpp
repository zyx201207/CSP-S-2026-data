#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,len=0;
bool check=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char> s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=len;j<=len+a;j++)s.push_back(c);
		len+=a;
	}
	for(int i=1;i<=n;i++)
		if(s[i]!=s[len-i+1])ans++;
	cout<<ans;
	return 0;
}
