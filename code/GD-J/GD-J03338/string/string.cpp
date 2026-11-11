#include <bits/stdc++.h> 
using namespace std;
int a,f[100005],cnt;
string w[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for (int i = 1;i <= a;i++)
	{
		cin >>f[i];
		cin >> w[i];
	}
	int l = 1,r = a;
	while(l < r){
		if (w[l] == w[r]){
			if (f[l] >= f[r]){
				f[l] = f[l] - f[r];
				f[r] = 0;
			}
			else{
				f[r] = f[r] - f[l];
				f[l] = 0;
			}
		}
		else{
			if (f[l] >= f[r]){
				f[l] = f[l] - f[r];
				cnt += f[r];
				f[r] = 0;
			}
			else{
				f[r] = f[r] - f[l];
				cnt += f[l];
				f[l] = 0;
			}
		}
		if (f[l] == 0)
		{
			l++;
		}
		if (f[r] == 0)
		{
			r--;
		}
	}
	cout << cnt;
	return 0;
}