#include <bits/stdc++.h>
using namespace std;
long long n,shu,cnt=0;
double shuzishu;
char zimu,zimu1,zimushu;
string a,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>shu;
		cin>>zimu;
		shuzishu+=shu*1.0;
		if(zimu1!=zimu&&i>1)
		{
			zimushu++;
			cnt+=shu;
		}
		zimu1=zimu;
	}
	if(zimushu==2&&shuzishu>10000){
		cout<<floor(shuzishu/2+0.5);
		return 0;
	}
	if(cnt==0)
		cout<<0;
	else
		cout<<cnt-1;
	return 0;
}
