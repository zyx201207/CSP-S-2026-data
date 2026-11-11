#include<iostream>
using namespace std;
long long gsh[200005];
char zf[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin >> n; 
	for(int i = 1;i <= n;i++)
	{
		cin >> gsh[i] >> zf[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(zf[l] != zf[r])
		{
			s+=min(gsh[l],gsh[r]);
		}
		
		
		if(gsh[l] == gsh[r])
		{
			l++;
			r--;
		}
		else if(gsh[l] < gsh[r])
		{
			gsh[r] -= gsh[l];
			l++;
		}
		else
		{
			gsh[l] -= gsh[r];
			r--;
		}

	}
	cout << s;
	return 0;
 } 
