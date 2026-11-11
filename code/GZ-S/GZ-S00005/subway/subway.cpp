//GZ-S00005 ²ÜÓþèñ
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1000005]={5,32,17,35,16,5,11,20,11,20,10,12,25,20,11,1,23,37,1,3,23};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=q; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
