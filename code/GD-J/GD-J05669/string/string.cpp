#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n];
	char b[n];
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
			s+=b[i];
	}
	//cout<<s;
	for(int l=0,r=s.size()-1;l<=((s.size()-1)/2),r>=((s.size()-1)/2+1);l++,r--)
	{
			if(s[l]!=s[r])
			{
				cnt++;
			}else
				break;
	}
	cout<<cnt;
}
