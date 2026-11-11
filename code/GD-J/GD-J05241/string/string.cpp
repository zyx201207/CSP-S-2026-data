#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans;
inline string strmul(string x,int n1)
{
	string r;
	for(int i=1;i<=n1;i++){r+=x;}
	return r;
}

bool check(int idx)
{
	return s[idx]==s[s.length()-idx-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a1;
		string c1;
		cin>>a1>>c1;
		s+=strmul(c1,a1);
	}
	for(int i=0;i<=s.length()/2;i++)
	{
		if(!check(i))
		{
			ans++;
//			s[s.length()-i-1]=s[i];
		}
	}
	cout<<ans; 
	return 0;
}



