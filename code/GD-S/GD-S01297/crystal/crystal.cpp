#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll qua,tim,cry[500005],res,add;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>qua>>tim;
	for(int m=1;m<=qua;m++)cin>>cry[m];
	sort(cry+1,cry+qua+1);
	for(int m=1;m<=qua;m++)
	{
		while(cry[m]==cry[m+1])add++,m++;
		ll timi=tim,resi=add+1,n=m-add-1;
		add=0;
		while(n>0)
		{
			if(timi-cry[m]+cry[n]>=0)
			{
				timi=timi-cry[m]+cry[n];
				resi++;
			}
			else break;
			n--;
		}
		
		res=max(res,resi);
	}
	cout<<res;
	return 0;
}
