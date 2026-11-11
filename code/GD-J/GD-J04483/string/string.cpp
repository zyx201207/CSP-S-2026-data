#include <bits/stdc++.h>
using namespace std;
long long n,c[200010],ans;
char a[200010];
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i] >> a[i];
		for(int j=1;j<=c[i];j++)
			str+=a[i];
	}
	long long len=str.length();
	for(int i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-i-1])
			ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
