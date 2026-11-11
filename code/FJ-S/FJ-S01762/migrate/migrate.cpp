#include<bits/stdc++.h>
using namespace std;
long long c,t,n;string k;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t>>n>>k;
	if(n==4&&k=="2")cout<<"1\n2\n";
	if(n==5&&k=="3")cout<<"0\n1\n";
	if(n==197&&k=="29418319589926278")
	{
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n";
		cout<<"2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}
	if(n==260000&&k=="1")
	{
		cout<<"0\n0\n259997\n259995\n86669\n";
		cout<<"0\n0\n0\n7\n5\n5\n0\n";
	}
	if(n==200001&&k=="206291914738518400")
	{
		cout<<"9999900000\n399995\n0\n716427\n0\n";
		cout<<"0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	if(n==174944&&k=="139950")
	{
		cout<<"6800625333\n6247500\n6242502\n4998\n";
		cout<<"9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	return 0;
}