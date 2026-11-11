//GZ-J00060  务川仡佬族苗族自治县县庆中学 田星辰 
#include<bits/stdddc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,b;d
	int n,a;
	long long ans=0,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
			ans++;
		}
	}
	long long l=0,r=ans-1;
	for(int i=0;i<=ans-1;i++)
	{
		if(s[l]!=s[r])
		{
			s[r]=s[l];
			sum++;
		}
		l++;
		r--;
	}
	cout << sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}


