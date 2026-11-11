#include<bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long; 

void run();

int main()
{
	freopen("migrate.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	run();
	
	return 0;
} 

i64 isN, maxD;
vector<i64> Pos;
vector<i64> lftArr, rigArr;

void runT()
{
	cin >> isN >> maxD;
	Pos.resize(isN);
	lftArr.resize(isN);
	rigArr.resize(isN);
	
	for(auto &p : Pos)
	{
		cin >> p;
	}
	
	
	if(isN <= 3)
	{
		cout << 0 << endl;
		return;
	}
	
	
	lftArr[0] = 0;
	if(Pos[1] - Pos[0] <= maxD)
	{
		lftArr[1] = 0;
	}
	else
	{
		lftArr[1] = 1;
	}
	
	for(i32 i = 2; i < isN; ++i)
	{
		if(Pos[i] - Pos[i-2] <= maxD || Pos[i] - Pos[i-1] > maxD)
		{
			lftArr[i] = i;
		}
		else
		{
			lftArr[i] = lftArr[i-1];
		}
	}
	
	rigArr[isN-1] = isN-1;
	if(Pos[isN-1] - Pos[isN-2] <= maxD)
	{
		rigArr[isN-2] = isN-1;
	}
	else
	{
		rigArr[isN-2] = isN-2;
	}
	
	for(i32 i = isN-3; i >= 0; --i)
	{
		if(Pos[i+2] - Pos[i] <= maxD || Pos[i+1] - Pos[i] > maxD)
		{
			rigArr[i] = i;
		}
		else
		{
			rigArr[i] = rigArr[i+1];
		}
	}
	
	i64 ans = 0;
	i64 lP = 0, rP = 3;
	i64 lFr = 0, rFr = 0;
	for(lP = 0; lP + 3 < isN; lP++)
	{
		while(Pos[lFr+1] - Pos[lP] <= maxD)
		{
			lFr += 1;
		}
		
		rP = max(rP, lP + 3);
		while(Pos[rP] - Pos[rFr] > maxD)
		{
			rFr += 1;
		}
			
		while(lFr > rFr + 1)
		{
			rP++;
			if(rP >= isN)
			{
				break;
			}
			while(Pos[rP] - Pos[rFr] > maxD)
			{
				rFr += 1;
			}
		}
		
		if(lFr == rFr + 1)
		{
			ans += (lP - lftArr[lP] + 1) * (rigArr[rP] - rP + 1);
		}
	}
	
	cout << ans << endl;
}


void run()
{
	i64 ct, tst;
	cin >> ct >> tst;
	for(i32 i = 0 ; i < tst; ++i)
	{
		Pos.clear();
		lftArr.clear();
		rigArr.clear();
		runT();
	}
}
