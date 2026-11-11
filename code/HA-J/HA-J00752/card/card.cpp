#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long n,m,a;
	cin >> n >> m;
	deque <unsigned long long> q1;
	deque <unsigned long long> q2;
	vector <unsigned long long> vec(n,0);
	for (unsigned long long i = 0;i < n;i++) 
	{
		cin >> a;
		q1.push_back(a);
	}
	while (!q1.size())
	{
		vector <bool> sk(n,false);
		q2.push_back(q1.front());
		for (unsigned long long i = 1;i < q1.size() ;i++)
		{
			if (sk[q1.front()])
			{
				do
				{
					q1.push_back(q2.back());
					sk[q1.back()] = false;
					q2.pop_back(); 
				}
				while (q2.back() != q1.front());
			}
			q2.push_back(q1.front());
			q1.pop_front();
			sk[q2.back()] = true;
		}
		while (!q2.size())
		{
			vec[q2.back() - 1]++;
			q2.pop_back();
		}
	}
	for (unsigned long long i = 0;i < m;i++)
	{
		cout << vec[i] << " "; 
	} 
}
