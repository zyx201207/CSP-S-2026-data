#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int zzN = 2e5 + 5;
ll zza[zzN];
ll zzm,zzn,zzans;
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> zzn >> zzm;
	for(ll zzi = 0; zzi < zzn; ++zzi)
	{
		cin >> zza[zzi];
	}
	
	sort(zza,zza + zzn);
	zzans = zza[zzn - 1];
	
	for(ll zzi = 1; zzi <= zzm - 1; ++zzi)
	{
		zzans = (zzans & zza[zzn - zzi - 1]);
	}
	
	cout << zzans;
	return 0;
}
