#include<bits/stdc++.h>
using namespace std;
#define int long long
int len[200005], len1[200005];
char c[200005], c1[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cge = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> len[i] >> c[i];
		len1[n - i + 1] = len[i];
		c1[n - i + 1] = c[i];
	}
	int last_1 = 0, last_2 = 0;
	for(int i = 1, j = 1;i <= n, j <= n;)//Ç° ºó 
	{
//		cout << i << " " << j << " " << cge << "\n";
		if(c[i] != c1[j])
		{
			if(len[i] - last_1 <= len1[j] - last_2)
			{
				cge += (len[i] - last_1);
				last_2 += (len[i] - last_1);
				i++;
				last_1 = 0;
			}
			else if(len[i] - last_1 > len1[j] - last_2)
			{
				cge += (len1[j] - last_2);
				last_1 += (len1[j] - last_2);
				j++;
				last_2 = 0;
			}
		}
		else {
			if(len[i] - last_1 <= len1[j] - last_2)
			{
				last_2 += (len[i] - last_1);
				i++;
				last_1 = 0;
			}
			else if(len[i] - last_1 > len1[j] - last_2)
			{
				last_1 += (len1[j] - last_2);
				j++;
				last_2 = 0;
			}
		}
	}
	cout << cge / 2;
	return 0;
}
