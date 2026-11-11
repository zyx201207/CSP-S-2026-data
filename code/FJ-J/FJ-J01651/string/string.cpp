#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,t,a,ans=-1,cnt=0;
	char b;
	cin>>n;
	string s,t1;
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		for(int j=0; j<a; j++) {
			s+=b;
			ans++;
		}
	}
	t1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=t1[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
