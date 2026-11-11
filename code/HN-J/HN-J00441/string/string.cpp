#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;

int n,len=0,ans=0;
string s;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1,a;i<=n;i++)
	{
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;	
	}
	
	string s1=s;
	reverse(s1.begin(),s1.end());
	
	int l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) ans++;
		l++;
		r--;	
	} 
	
	cout<<ans;
	return 0;
}
