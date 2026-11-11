#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool x=1,y=1;
int cha;

bool cmp(int x,int y) {
	return x>y;
}

int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin >> n >> m;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		if (a[i] != i) x=0;
		if (i == 2) cha=a[2]-a[1];
		if (i>2 && a[i]-a[i-1]!=cha) y=0;
	}
	sort(a+1,a+1+n,cmp);
	if (x)  cout << m;
	else if (y)  cout << m/cha;

	return 0;
}
