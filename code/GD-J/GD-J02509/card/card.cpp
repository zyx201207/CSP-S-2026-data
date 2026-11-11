#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n),c(m+2,0);
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0;i < n;i++)
	{
		vector<int> table(n+2);
		int tsz = 0;
		for (int j = i;j < n;j++)
		{
			for (int k = 0;k < tsz;k++)
			{
				if(table[k] == a[j]){
					tsz = 1+k;
					break;
				}
			}
			table[++tsz] = a[j];
		}
		vector<bool> v(m+2,0);
		for (int j = 0;j < tsz;j++)
		{
			if(!v[table[j]]){
				v[table[j]] = 1;
				c[table[j]]++;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout<< c[i] <<' ';
	}
	return 0;
}
//qwq
