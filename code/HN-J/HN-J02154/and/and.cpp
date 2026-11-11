#include <bits/stdc++.h>
using namespace std;
string a[200005];
int b[200005];
int answer;
void zhuanhuan(int s,string a[],int i)
{
	char c[100005] = {};
	int cur = 1;
	while(s != 0)
	{
		c[cur++] = s % 2;
		s /= 2;
	}
	for(int j = cur-1;j >= 0;j--)
	{
		a[i] += c[j];
	}
	return;
}
void change(string ans,int answer)
{
	int len = ans.size();
	int q = 1;
	for(int i = len;i >= 0;i--)
	{
		answer += ans[i] * q;
		q *= 2;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	string ans = "";
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		int s;
		cin >> s;
		b[i] = s;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		zhuanhuan(b[i],a,i);
	}
	for(int i = 1;i <= m;i++)
	{
		ans = ans & a[i];
	}
	change(ans,answer);
	cout << answer;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
