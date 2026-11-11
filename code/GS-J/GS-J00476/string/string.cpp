#include<bits/stdc++.h>

using namespace std;
struct lett
{
	int t;
	char tmp;
};
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long length = 0;
	lett ch[100005];
	for(int i = 1; i <= n; i++)
	{
		cin >> ch[i].t >> ch[i].tmp;
		length += ch[i].t;
	}
	long long pos1 = 1, pos2 = n, ans = 0, tle1 = 1, tle2 = 1;
	while(pos1 <= pos2)
    {
        if(ch[pos1].tmp != ch[pos2].tmp)
            ans++;
        if(tle1 >= ch[pos1].t)
            pos1++, tle1 = 0;
        if(tle2 >= ch[pos2].t)
            pos2--, tle2 = 0;
            tle1++, tle2++;
    }
    cout <<ans;
	return 0;
}

