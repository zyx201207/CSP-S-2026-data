#include <bits/stdc++.h> 
using namespace std;

long long func(long long* nums, int size, int n)
{
	long long sum = nums[size - 1] * n, t = 0;
	for(int i = 0; i < size - n + 1; i++)
	{
		t = 0;
		for (int j = i; j < i + n; j++)
		{
			t += nums[i + n - 1] - nums[j];	
		}
		if(t <= sum) sum = t;
	}
	return sum;
}

bool is_deng(long long* nums, int size)
{
	long long cha = nums[1] - nums[0];
	for (int i = 2; i< size; i++)
	{
		if (nums[i] - nums[i - 1] != cha) return false;
	}
	return true;
}

bool cmd(long long n1, long long n2)
{
	return (n1 < n2);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	long long n,m,cha;
	cin >> n >> m;
	long long crystals[n+2], t1 = 1, t2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> crystals[i]; 
	}
	sort(crystals,crystals+n);
	
	
	if (m >= (crystals[n-1] - crystals[0] )* n) cout << n;
	
	else if (is_deng(crystals, n))
	{
		cha = crystals[1] - crystals[0];
		while(m > t2)
		{
			t2 = t1 * (t1 - 1) / 2 * cha;
			t1 ++;
		}
		t1--;
		cout << t1 - 1;
	}
	
	else if (m < func(crystals, n, 2)) cout << 1;
	
	
	
	else
	{
		while(m > t2)
		{
			t2 = func(crystals, n, t1);
			t1++;
		}
		cout << t1 - 1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
