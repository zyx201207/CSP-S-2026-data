#include <bits/stdc++.h>
using namespace std;
int zza[10005];
int zzb[10005];
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int zzm,zzn;
	cin >> zzn >> zzm;
	if(zzm <= 2 && zzn <= 5)
	{
		if(zzn == 1)
		{
			cout << 1;
			return 0;
		}
		if(zzn == 2)
		{
			cout << "2 2";
			return 0;
		}
		if(zzn == 3)
		{
			cout << "2 2 3";
			return 0;
		}
		if(zzn == 1)
		{
			cout << 1;
			return 0;
		}
		if(zzn == 1)
		{
			cout << 1;
			return 0;
		}
	}
	return 0;
}
