#include <bits/stdc++.h>
#define ST struct
#define FR freopen
#define RT return
#define IL inline

#define FOR_P(i, a, b, c) for (int i = a; i <= b; i += c)
#define FOR_D(i, a ,b, c) for (int i = a; i >= b; i -= c)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using vd = void;
using in = int;
using cr = char;
using st = string;

IL vd FastIO(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}

st R_car, X_car, R_sit, X_sit;

IL vd SetUp()
{
	
	
	RT ;
}

IL vd Solve()
{
	SetUp();
	
	cin >> R_car >> R_sit;
	cin >> X_car >> X_sit;
	
	if (R_car == X_car) // question 1
	{
		if (R_sit[0] == X_sit[0] && R_sit[1] == X_sit[1]) // question 2
		{
			if (!((R_sit[2] == 'C' && X_sit[2] == 'D') || (R_sit[2] == 'D' && X_sit[2] == 'C'))) // quesion 3
			{
				if (!((R_sit[2] == 'C' && X_sit[2] == 'A') || (R_sit[2] == 'A' && X_sit[2] == 'C'))) // question 4
				{
					cout << "1111\n";
				}
				
				else
				{
					cout << "1110\n";
				}
			}
			
			else
			{
				cout << "1100\n";
			}
		}
		
		else
		{
			cout << "1000\n";
		}
	}
	
	else
	{
		cout << "0000\n";
	}
	
	RT ;
}

int main()
{
	FR("travel.in", "r", stdin);
	FR("travel.out", "w", stdout);
	FastIO();
	Solve();
	RT 0;
}