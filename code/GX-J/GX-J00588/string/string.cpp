#include <iostream>
#include <vector>
using namespace std;
long long n,left_zj,right_zj;
long long tem_1,sum_1;
long long ce_1 = 0;
vector<long long> numb_1;
vector<char> ty_1;
char tem_2;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>tem_1;
		numb_1.push_back(tem_1);
		cin>>tem_2;
		ty_1.push_back(tem_2);
	}
	left_zj = 0;
	right_zj = n-1;
	while(1)
	{
		if(left_zj != right_zj && right_zj > left_zj)
		{
			if(ty_1[left_zj] != ty_1[right_zj])
			{
				if(numb_1[left_zj] > numb_1[right_zj])
				{
					ce_1 += numb_1[right_zj];
					numb_1[left_zj] -= numb_1[right_zj];
					numb_1[right_zj] = 0;
					right_zj -= 1;
				}
				else if(numb_1[left_zj] < numb_1[right_zj])
				{
					ce_1 += numb_1[left_zj];
					numb_1[right_zj] -= numb_1[left_zj];
					numb_1[left_zj] = 0;
					left_zj += 1;
				}
				else
				{
					ce_1 += numb_1[left_zj];
					numb_1[right_zj] = 0;
					numb_1[left_zj] = 0;
					left_zj += 1;
					right_zj -= 1;
				}
			}
			else
			{
				if(numb_1[left_zj] > numb_1[right_zj])
				{
					numb_1[left_zj] -= numb_1[right_zj];
					numb_1[right_zj] = 0;
					right_zj -= 1;
				}
				else if(numb_1[left_zj] < numb_1[right_zj])
				{
					numb_1[right_zj] -= numb_1[left_zj];
					numb_1[left_zj] = 0;
					left_zj += 1;
				}
				else
				{
					numb_1[right_zj] = 0;
					numb_1[left_zj] = 0;
					left_zj += 1;
					right_zj -= 1;
				}
			}
		}
		else
		{
			cout<<ce_1;
			break;
		}
	}
	return 0;
}
