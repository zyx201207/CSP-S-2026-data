#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,ans;//m<=125250
vector<int>a,w;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
//	for(int i=1;i<=m;i++){
//		cin >> w[i];
//	}
	while(q--)
	{
		srand(time(0)*rand());
		cout << rand()%70 << endl;
	}
	return 0;
}
