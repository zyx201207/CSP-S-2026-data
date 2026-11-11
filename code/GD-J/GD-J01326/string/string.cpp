#include<bits/stdc++.h>
#define int long long
#define pii pair<long long,long long>
using namespace std;
int n,sum=0,a;
char c;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
