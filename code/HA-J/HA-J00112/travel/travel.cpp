#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string a,ab,b,bb;
	cin >> a >> ab >> b >> bb;
	if(a==b&&a!="01"&&a!="16") cout << 1; 
	else 
	{
		for(int i=1;i<=4;i++)
		{
			cout << 0;
		}
		return 0;
	}
	
	if(ab[0]==bb[0]&&ab[1]==bb[1]) cout << 1;
	else cout << 0;
	if(ab[2]=='C'&&bb[2]=='D'||ab[2]=='D'&&bb[2]=='C') cout << 1;
	else cout << 0;
	if(ab[2]-bb[2]==1||ab[2]-bb[2]==-1) cout << 1; 
	else cout << 0;
	return 0;
}
