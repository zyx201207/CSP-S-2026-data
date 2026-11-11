//贵阳市观山湖区外国语实验中学林浩宇GZ-J00118 
#include <bits/stdc++.h>
using namespace std;
struct s
{
	int size;
	int shu;
}a[20005];
bool cmp(s a,s b)
{
	return a.shu > b.shu;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		string s = "";
		cin >> x;
		a[i].shu = x;
		a[i].size = s.size();
	}
	sort (a + 1,a + n + 1,cmp);
	int c = a[1].shu; 
	for(int i = 2;i <= m;i ++)
	{
		c = c & a[i].shu;
	}
	cout << c;
	return 0;
	
}
