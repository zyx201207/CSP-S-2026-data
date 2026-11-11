#include<bits/stdc++.h>
using namespace std;
long long m;
long n;
long long x;
long long tot = 0;
long long he = 0;
long long a[10005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(long i = 1;i<=n;i++)
	{
		cin>>a[i];
		he += a[i];
	}
	long  ave = he/n;
	//cout<<ave<<" ";
	long y = n/2+1;
	long l = y;
	long r = y;
	//cout<<l<<" "<<endl;
	while(m > 0)
	{
		while(a[l] < ave && a[r] > ave)
		{
			if(m == 0) 
			{
				break; 
			}
			a[l]++;
			a[r]--;
			m--;
			//cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<endl;
		}
		if(l >= 1 && r >= 1)
		{
			l--;
			r++;
		}
		else break;
	}
	for(long i = 1;i<=n;i++)
	{
		if(a[i] == ave) tot++;
	}
	cout<<tot;
	return 0;
}
