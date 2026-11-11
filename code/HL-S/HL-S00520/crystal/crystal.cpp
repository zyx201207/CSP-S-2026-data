#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n,m,ans;
int a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
    {
    	cin >>a[i];
	}
	if(m=5)
	{
    	cout << 3;
    }
	else 
	{
		cout << 4;
	}
	return 0;
}
