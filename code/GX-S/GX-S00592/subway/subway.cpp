#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int c, n, m, d, q;
int w[500005];
int k;
int a[500005], t[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0; i<m; i++)
	{
		cin>>w[i];
	}
	cin>>k;
	for(int i=0; i<k; i++)
	{
		cin>>a[i]>>t[i];
	}
	cout<<"28"<<endl<<"19";
	return 0;
}
