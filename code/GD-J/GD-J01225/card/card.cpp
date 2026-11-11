#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int qua,num,car[N],des[N],res[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>qua>>num;
	for(int m=1;m<=qua;m++)cin>>car[m];
	for(int m=1;m<=qua;m++)
	{
		memset(des,0,sizeof(des));
		for(int n=m;n<=qua;n++)
		{
			bool fla=0;
			for(int b=m;b<=n;b++)
			{
				if(des[b]==car[n])fla=1;
				if(fla)des[b]=0;
			}
			des[n]=car[n];
		}
		for(int n=1;n<=qua;n++)cout<<des[n]<<" ";
		cout<<"\n";
		for(int n=m;n<=qua;n++)if(des[n])res[des[n]]++;
	}
	for(int m=1;m<=num;m++)cout<<res[m]<<" ";
	return 0;
}
