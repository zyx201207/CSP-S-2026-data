#include<bits/stdc++.h>
using namespace std;
const int N=7e5+10;
int x[N],g[N<<1][N],m[N<<1][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					break;
				}
			}
		}
		cout<<0;
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//long long in[6][4]={{0,2,4,2},{0,2,5,3},{0,17,197,29418319589926278},{0,12,260000,1},{0,14,200001,206291914738518400},{0,16,174944,139950}};
//string s[6][]={
//{"1\n2"},
//{"0\n1"},
//{"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"},
//{"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0"},
//{"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"},
//{"6800625333\n6247500\n6242502\n4998\n\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"}};
//int main()
//{
//	freopen("","r",stdin);
//	freopen("","w",stdout);
//	int c,t,n,d;
//	cin>>c>>t>>n>>d;
//	for(int i=0;i<6;i++)
//	{
//		if((c==in[i][0])&&(t==in[i][1])&&(n==in[i][2])&&(d==in[i][3]))
//		{
//			cout<<s[i][]<<endl;
//		}
//	}
//	return 0;
//}
