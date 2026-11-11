#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000];char c[1000000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	string s="";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	int len=s.size()-1,ans=0;
	for(int i=0,j=len;i<j;i++,j--)
		if(s[i]!=s[j])
			ans++;
			
	cout<<ans;
	return 0;
}
