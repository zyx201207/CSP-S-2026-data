#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,ans=0,cnt=0;
	string s,s1;
	char a;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >>k >> a;
		for(int j=0;j<k;j++)
		{
			s[ans+j]=a;
		}
		ans+=k;
	}
	if(ans%2==0)
	{
		for(int i=0;i<ans/2;i++)
		{
			s1[i]=s[i];
		}
		for(int i=ans-1;i>=ans/2;i--)
		{
			cout << s1[ans-i-1] << " " << s[i] << endl;
			if(s1[ans-i-1]!=s[i])
			{
				cnt++;
			}
		}
	}
	else
	{
		for(int i=0;i<(ans-1)/2;i++)
		{
			s1[i]=s[i];
			
		}
		for(int i=ans-1;i>=(ans+1)/2;i--)
		{
			if(s1[ans-i-1]!=s[i])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
