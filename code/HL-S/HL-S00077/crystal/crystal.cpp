#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
int cnt;
long long sum;
long long ans;
long long c;
long long num;
long long d;
long long e=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] == i)
        {
            cnt++;
        }
        if(i == 2)
        {
            c = a[i] - a[i-1];
            if(m > c)
            {
				e++;
           	    d += 2;	
			}
            
        }
        if(i != 1 && i != 2)
        {
            if(a[i] - a[i-1] == c)
            {
                num++;
                if(d+c*e <= m)
                {
                    d+=c;
                    e++;
                    continue;
                }
            }
        }

        if(ans + i <= m)
        {
            ans += i;
            sum = i;
        }
    }
    sort(a,a+n);
    if(cnt == n)
    {
        for(int i=n;i<=m;i++)
        {
            if(ans + i <= m)
            {
                ans += i;
                sum = i;
            }
            else
             {
                 break;
             }
        }
        if(sum+1 > n)
        {
            cout << n;
            return 0;
        }
        cout << sum+1;
        return 0;
    }
    if(num == n-2)
    {
        cout << e;
        return 0;
    }
    cout << n << endl;
    return 0;
}

