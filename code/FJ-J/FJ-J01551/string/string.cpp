#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int zzN = 9e7 + 5;
ll zza[zzN];
ll zzp = 1;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int zzn;
	cin >> zzn;
	
	for(ll zzi = 1; zzi <= zzn; ++zzi)
	{
		int zzq;
		char zzw;
		cin >> zzq >> zzw;
		for(ll zzj = zzp; zzj <=  zzq + zzp; ++zzj)
		{
			zza[zzj] = (zzw - '0');
		}
		zzp += zzq;
	}
	zzp--;
	ll zzans = 0;
	ll zzmid1 = zzp;
	if(zzp % 2 == 1)
	{
		zzmid1 = (zzmid1 + 1) / 2;
		for(ll zzi = 1,zzj = zzp; zzi < zzmid1,zzj > zzmid1; )
		{
			if(zza[zzi] != zza[zzj])
			{
				zzans++;
			}
			zzi++,zzj--; 
		}
	}
	else
	{
		zzmid1 /= 2;
		for(ll zzi = 1,zzj = zzp; zzi <= zzmid1,zzj >= zzmid1 + 1;)
		{
			if(zza[zzi] != zza[zzj])
			{
				zzans++;

			}
			zzi++,zzj--;
		}
	}
	
	cout << zzans;
	return 0;
}
