#include <bits/stdc++.h>
using namespace std;
string s1,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","r",stdin);
	long long n,a;
	char c;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> c;
		for(int j=0;j<a;j++)
			s+=c;
	}
	int z=s.size();
	for(int i=0;i<z;i++)
		s1[i]=s[i];
	long long ans=0;
	if(z%2==1){
		for(int i=0;i<(z+1)/2;i++)
			swap(s[i],s[z-i-1]);
	}
	else{
		for(int i=0;i<z/2;i++)
			swap(s[i],s[z-i-1]);
	}
	if(z%2==1)
	{
		for(int i=0;i<z;i++)
		{
			if(s[i]!=s1[i]){
				ans++;              
				s[i]=s1[i];
				for(int j=0;j<(z+1)/2;j++)
					swap(s[j],s[z-j-1]);
			}
		}
	}
	else{
		for(int i=0;i<z;i++)
		{
			if(s[i]!=s1[i]){
				ans++;              
				s[i]=s1[i];
				for(int j=0;j<z/2;j++)
					swap(s[j],s[z-j-1]);
			}
		}
	}
	cout << ans;
	return 0;
}
