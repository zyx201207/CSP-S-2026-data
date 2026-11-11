#include<bits/stdc++.h>
using namespace std;
long long t[2*100005];
char tc[2*100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long p=0;
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> t[i];
		cin >> tc[i];
	}
	int l=0,r=n-1;
	while(l<r)
	{
		int tl=t[l],tr=t[r];
		if(tc[l]==tc[r])
		{
			t[l]-=min(tl,tr);
			t[r]-=min(tl,tr);
		}
		else
		{
			p+=min(tl,tr);
			t[l]-=min(tl,tr);
			t[r]-=min(tl,tr);
		}
//		cout << "p " << p << '\n';
//		cout << "t[l] " << t[l] << '\n';
//		cout << "t[r] " << t[r] << '\n';
//		cout << "l " << l << '\n';
//		cout << "r " << r << '\n'<< '\n';
		if(t[l]==0)
		{
			l++;
		}
		if(t[r]==0)
		{
			r--;
		}
	}
	cout << p;
	return 0;
}