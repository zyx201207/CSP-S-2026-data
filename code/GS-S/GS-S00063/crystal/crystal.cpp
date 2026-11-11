#include <bits/stdc++.h>
using namespace std;
int n;
long long m;	
long long a[11451];	
long long temp;
long long ans[11451];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
	//	cout << "-----"<<"   "<<i<<"--->"<<a[i]<<"   "<<"-----"<<endl; 
		for(int j=i-1;j>0;j--)
		{
			if(temp+(a[i]-a[j])<=m)
			{
				ans[i]++;
				//cout << "+1"<<"   ";
				temp+=(a[i]-a[j]);
			}
			else
			{
				break;
			}
		}
		//cout << endl;
		temp=0;
	}
	sort(ans+1,ans+n+1);
	cout << ans[n]+1;
	return 0; 
}
