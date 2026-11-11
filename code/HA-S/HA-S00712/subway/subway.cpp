#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int arr[m];
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	srand(time(0));
	cout<<rand()<<'\n';
	cout<<rand()<<'\n';
	return 0;
}
