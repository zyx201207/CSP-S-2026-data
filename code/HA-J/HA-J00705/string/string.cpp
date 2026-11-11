#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans;
string s,s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++) s+=a;
		sum+=x;
	}
	for(int i=0;i<=sum/2-1;i++) s1+=s[i];
	for(int i=sum-1;i>=(sum+1)/2;i--) s2+=s[i];
	for(int i=0;i<=sum/2-1;i++){
		if(s1[i] != s2[i]) ans++;
	}
	cout<<ans;
}

