#include<bits/stdc++.h>
using namespace std;
long long n,ans,total;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string z;
		cin>>x>>z;
		total+=x;
		for(int j=1;j<=x;j++)s+=z;
	}
	for(int i=0;i<total/2;i++){
		if(s[i]!=s[total-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
