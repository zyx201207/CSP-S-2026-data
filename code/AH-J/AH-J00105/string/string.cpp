#include <bits/stdc++.h>
using namespace srd;
string c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,q;
    cin >> n;
    string ans;
    for (int i = 1;i <= n;i++)
    {
        cin >> q >> ans;
        for (int j = 1;j <= q;j++)
        {
            c[j-1] += ans;
        }
    }
    int ans = 0;
    int l = 0;r = s.size()-1;
    for (int k = 0;k < s.size()-1;k++)
    {
        int mid = (l + r) / 2;
        if (l < r)
        {
	  if (c[l] != c[r])
	    {
	      c[l] = c[r];
	      ans++;
	      l++;
	      r--;
	    }
	}
        if (l == r)
        {
	  break;
        }
	if (l > r)
	{
	  break;
	}
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
