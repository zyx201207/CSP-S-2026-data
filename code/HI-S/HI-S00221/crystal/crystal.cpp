#include<bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long; 

void run();

int main()
{
	freopen("crystal.out", "w", stdout);
	freopen("crystal.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	run();
	
	return 0;
} 

i64 cryN, optN;
vector<i64> engArr;
vector<i64> sumArr;

    
i64 maxGet(i64 tagEng, i64 backPos)
{
//	cout << "tag" << tagEng << endl;
//	if(tagEng != 5)
//	{
//		return 0;
//	}
//	i64 l = -1, r = cryN;
//	while(l + 1 < r)
//	{
//		i64 mid = l + (r-l) / 2;
//		if(engArr[mid] > tagEng)
//		{
//			r = mid;
//		}
//		else
//		{
//			l = mid;
//		}
//	}
//	i64 backPos = l;
	if(sumArr[backPos] + optN >= engArr[backPos] * (backPos+1))
	{
		return backPos + 1;
	}
	
	i64 l = -1, r = backPos;
	i64 frontPos;
	while(l + 1 < r)
	{
		i64 mid = l + (r-l) / 2;
		if(sumArr[backPos] - sumArr[mid] + optN < engArr[backPos] * (backPos - mid) )
		{
//			cout << "r" << mid << endl;
			l = mid;
		}
		else
		{
//			cout << "l" << mid << endl;
			frontPos = r = mid;
		}
	}
	
//	i64 frontPos = l;
	return backPos - frontPos;	
}

void run()
{
	cin >> cryN >> optN;
	engArr = vector<i64>(cryN);
	for(auto &eng : engArr)
	{
		cin >> eng;
	}
	sort(engArr.begin(), engArr.end());
	
	sumArr = vector<i64>(cryN);
	sumArr[0] = engArr[0];
	for(i32 i = 1; i < cryN; ++i)
	{
		sumArr[i] = sumArr[i-1] + engArr[i];
//		cout << sumArr[i] << endl;
	}
	
	engArr.push_back(1e18);
	
	i64 ans = 1;
	for(i32 i = 0; i < cryN; i++ )
	{
		if(engArr[i] != engArr[i+1])
		{
			ans = max(ans, maxGet(engArr[i], i));
		}
	}
	
	cout << ans;
	
}
