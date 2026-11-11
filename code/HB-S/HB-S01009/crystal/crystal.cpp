#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int energy[MAXN];

struct node
{
	long long num;	//The number.
	long long sum;	//The number of The number.
	long long dif;	//The differences between The number and the most common number.
};
node cnt1[MAXN], cnt2[MAXN];

bool cmp(node n1, node n2)
{
	return n1.sum > n2.sum;
}

bool cmp2(node n1, node n2)
{
	return n1.dif < n2.dif;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m;
	long long p = 2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> energy[i];
		
		for (int j = 1; j <= i; j++)
			if (cnt1[j].num == energy[i])
				cnt1[j].sum++;
			else
			{
				cnt1[i].num = energy[i];
				cnt1[i].sum = 1;
			}
	}
	sort(cnt1 + 1, cnt1 + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (cnt1[i].num < cnt1[1].num)
		{
			cnt2[i].num = cnt1[i].num;
			cnt2[i].dif = cnt2[1].num - cnt2[i].num;
			cnt2[i].sum = cnt2[i].sum;
		}
	}
	sort(cnt2 + 1, cnt2 + 1 + n, cmp2);
	while (m >= cnt2[p].dif)
	{
		m = m - cnt2[p].dif;
		cnt2[p].sum--;
		cnt2[1].sum++;
		if (cnt2[p].sum <= 0)
			p++;
	}
	cout << cnt2[1].sum << endl;
//	cout << "Do not think for one momment that because you are who you are, you cannot be what you want you to be." << endl;
	return 0;
}
