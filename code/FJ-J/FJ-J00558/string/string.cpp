#include <bits/stdc++.h>
using namespace std;
long long n,a[1000005],l,r,ans=0;
char b[1000005];
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s=s+string(a[i],b[i]);
	}
	l=0;
	r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
