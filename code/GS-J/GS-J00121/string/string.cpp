#include<bits/stdc++.h>
using namespace std;

long long n,L=0,ai,ans=0;char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;}
	for(int i = 1;i<=n;i++){
		cin >> ai >> a;
		for(int i = 1;i<=ai;i++)
		{
			s+=a;
		}
		L+=ai;
	}
	for(int i = 0;i<L/2;i++)
	{
		char abs=s[i],acs=s[L+1-i];
		if(abs==acs)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
