#include<bits/stdc++.h>
using namespace std;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ans=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++)c.push_back(b);
	}
	for(long long i=1;i<=c.size()/2;i++){
		if(c[i]!=c[n-i])ans++;
	}
	cout<<ans;
	return 0;
}
