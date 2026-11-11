#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull len[200005];
ull a2[200005];
ull a[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ull n;
	char c[200005];
	char c2[200005];
	
	scanf("%lld", &n);
	for(ull i = 1;i <= n;i++){
		scanf("%lld %c", a+i, c+i); 
		len[i] = len[i-1] + a[i]; 
	}
	ull mid = (len[n] + 1) / 2;
	//cout << "mid = " << mid << endl;
	if(len[n] % 2 == 0){
		//cout << "情况1\n";
		ull mp, cnt;
		ull ans = 0;
		for(ull i = 1;i <= n;i++){
			if(len[i] >= mid)
			{
				mp = i;
				break;
			}
		}
		if(len[mp] == mid){
			//cout << "for1\n";
			cnt = 0;
			for(ull i = mp + cnt;i <= n;i++){
				a2[cnt] = a[i];
				c2[cnt] = c[i];
				cnt++;
			}
		}
		else{
			//cout << "for2\n";
			a2[1] = len[mp] - mid;
			c2[1] = c[mp];
			len[mp] = mid;
			a[mp] = len[mp] - len[mp-1];
			cnt = 1;
			for(ull i = mp + cnt;i <= n;i++){
				cnt++;
				a2[cnt] = a[i];
				c2[cnt] = c[i];
			}
		}
//		//cout << "str1:\n"; 
//		for(ull i = 1;i <= mp;i++)
//			cout << a[i] << " " << c[i] << endl;
//		//cout << "str2:\n"; 
//		for(ull i = 1;i <= cnt;i++)
//			cout << a2[i] << " " << c2[i] << endl;
		ull ps1 = mp, ps2 = 1;
		while(mid>0&&ps1>0&&ps2<=cnt){
			if(a[ps1] == a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a[ps1]; 
				}
				mid -= a[ps1];
				ps1--, ps2++;
			}
			if(a[ps1] > a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a2[ps2];
				}
				mid -= a2[ps2];
				a[ps1] -= a2[ps2]; 
				ps2++;
			}
			if(a[ps1] < a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a[ps1];
				}
				mid -= a[ps1];
				a2[ps2] -= a[ps1]; 
				ps1--;
			}
		}
		printf("%lld", ans);
	}
	else
	{
		//cout << "情况2\n";
		ull mp, cnt;
		ull ans = 0;
		for(ull i = 1;i <= n;i++)
		{
			if(len[i] >= mid)
			{
				mp = i;
				break;
			}
		}
		if(len[mp] == mid)
		{
			//cout << "for1\n";
			cnt = 1;
			for(ull i = mp + cnt;i <= n;i++)
			{
				a2[cnt] = a[i];
				c2[cnt] = c[i];
				cnt++;
			}
		}
		else
		{
			//cout << "for2\n";
			a2[1] = len[mp] - mid;
			c2[1] = c[mp];
			len[mp] = mid - 1;
			a[mp] = len[mp] - len[mp-1];
			cnt = 2;
			for(ull i = mp + cnt - 1;i <= n;i++)
			{
				a2[cnt] = a[i];
				c2[cnt] = c[i];
				cnt++;
			}
		}
//		//cout << "str1:\n"; 
//		for(ull i = 1;i <= mp;i++)
//			cout << a[i] << " " << c[i] << endl;
//		//cout << "str2:\n"; 
//		for(ull i = 1;i < cnt;i++)
//			cout << a2[i] << " " << c2[i] << endl;
		ull ps1, ps2 = 1;
		if(a[mp] > 1) ps1 = mp;
		else ps1 = mp - 1;
		while(mid!=0&&ps1>0&&ps2<=cnt){
			if(a[ps1] == a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a[ps1];
				}
				mid -= a[ps1];
				ps1--, ps2++;
			}
			if(a[ps1] > a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a2[ps2];
				}
				mid -= a2[ps2];
				a[ps1] -= a2[ps2]; 
				ps2++;
			}
			if(a[ps1] < a2[ps2]){
				if(c[ps1] != c2[ps2]){
					ans = ans + a[ps1];
				}
				mid -= a[ps1];
				a2[ps2] -= a[ps1]; 
				ps1--;
			}
		}
		printf("%lld", ans);
	}
	return 0;
}
