#include <bits/stdc++.h>
using namespace std;
long long cst[200005];
long long pref[200005];
int main()
{
	const long long drift = 100000;
	//在所有数组操作的时候进行drift
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long max_num = -1;
	cin >> n;
	cin >> m;
	long long temp_max = INT_MIN;
	for(long long i = 0;i < n;i++)
	{
		long long temp;
		cin >> temp;
		temp += drift;
		if(temp < 0 || temp >= 200005)
		{
			cout << 2;
		}
		cst[temp]++;
		temp_max = max(temp_max,temp);
		//应该不需要Drift 
	}
	for(long long i = 0;i < temp_max;i++)
	{
		if(cst[i] != 0)
		{
			for(long long j = 0;j <= m;j++)
			{
				if(j == 0)
				{
					pref[i] += cst[i]; 
				}
				else
				{
					pref[i+j] += min((long long)floor(m/j),cst[i]);
				}
			}
		}
	}
	/*debuging
	for(int i = 0;i < temp_max - drift;i++)
	{
		cout << pref[i+drift] << endl;	
	} 
	*/
	for(long long i = 0;i < temp_max;i++)
	{
		max_num = max(max_num,pref[i]);
	}
	long long tgt = 0;
	for(long long i = 0;i < temp_max;i++)
	{
		if(max_num = pref[i])
		{
			tgt = i;
		}
	}
	for(long long j = -m;j < 0;j++)
	{
		max_num -= min((long long)floor(m/j),cst[tgt+j]);
	}
	return 0;	
} 
