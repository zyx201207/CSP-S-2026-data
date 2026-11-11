#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s="";
	int a;
	char z;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> z;
		for(int j=1;j<=a;j++)
		{
			s+=z;
		}
	}
	int sz=s.size()/2+(s.size()%2);
	int sum=0;
	if(s.size()%2==1)
	{
		for(int i=0;i<sz;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				sum++;
			}
		}
    }
    else
    {
    	for(int i=0;i<=sz;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
