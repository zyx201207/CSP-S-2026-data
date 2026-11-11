#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, m;
int a[N];
pair<int, int> b[N];

int main()
{
    freopen("crystal.in", "r", stdin);//remember!
    freopen("crystal.out", "w", stdout);//remember!
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int cnt = 1;
    b[0] = {a[0], 0};
    for(int i = 0; i < n; i++)
    {
        if(a[i] != a[i - 1])
        {
            b[++cnt].first = a[i];
            b[cnt].second = i;
        }
    }
    b[++cnt] = {0x3f3f3f3f, n};
    int ind = 0;
    int l = 0, r = -1;
    for(int i = 0; i < cnt; i++)
    {
        if(b[i + 1].second - b[i].second > r - l + 1)
        {
            ind = i;
            l = b[i].second;
            r = b[i + 1].second - 1;
        }
    }
    //cout << "[" << l << "," << r << "] (" << b[ind].first << ")" << endl;
    int sum = 0, h = b[ind].first;
    while(sum <= m)
    {
        // if((b[ind + 1].first - h) * (r - l + 1) <= m - sum && (h - a[l - 1]) <= m - sum)
        // {
        //     if((((b[ind + 1].first - h) * (r - l + 1) < (h - a[l - 1])) || l <= 0) && r < n - 1)
        //     {
        //         sum += (b[ind + 1].first - h) * (r - l + 1);
        //         ind++;
        //         h = b[ind].first;
        //         r = b[ind + 1].second - 1;
        //     }
        //     else
        //     {
        //         l--;
        //         sum += (h - a[l]);
        //     }
        // }
        // else if(((b[ind + 1].first - h) * (r - l + 1) > m - sum && (h - a[l - 1]) <= m - sum) || (r >= n - 1 && (h - a[l - 1]) <= m - sum))
        // {
        //     l--;
        //     sum += (h - a[l]);
        // }
        // else if(((b[ind + 1].first - h) * (r - l + 1) <= m - sum && (h - a[l - 1]) > m - sum) || (l <= 0 && (b[ind + 1].first - h) * (r - l + 1) <= m - sum))
        // {
        //         sum += (b[ind + 1].first - h) * (r - l + 1);
        //         ind++;
        //         h = b[ind].first;
        //         r = b[ind + 1].second - 1;
        // }
        // else
        // {
        //     break;
        // }

        if(l > 0 && r < n - 1)
        {
            if((b[ind + 1].first - h) * (r - l + 1) <= m - sum && (h - a[l - 1]) <= m - sum)
            {
                if((((b[ind + 1].first - h) * (r - l + 1) < (h - a[l - 1])) || l <= 0))
                {
                    sum += (b[ind + 1].first - h) * (r - l + 1);
                    ind++;
                    h = b[ind].first;
                    r = b[ind + 1].second - 1;
                }
                else
                {
                    l--;
                    sum += (h - a[l]);
                }
            }
            else if(((b[ind + 1].first - h) * (r - l + 1) > m - sum && (h - a[l - 1]) <= m - sum))
            {
                l--;
                sum += (h - a[l]);
            }
            else if(((b[ind + 1].first - h) * (r - l + 1) <= m - sum && (h - a[l - 1]) > m - sum))
            {
                    sum += (b[ind + 1].first - h) * (r - l + 1);
                    ind++;
                    h = b[ind].first;
                    r = b[ind + 1].second - 1;
            }
            else
            {
                break;
            }
        }
        else if(l > 0 && r >= n - 1 && (h - a[l - 1]) <= m - sum)
        {
            l--;
            sum += (h - a[l]);
        }
        else if((l <= 0 && r < n - 1) && (b[ind + 1].first - h) * (r - l + 1) <= m - sum)
        {
            sum += (b[ind + 1].first - h) * (r - l + 1);
            ind++;
            h = b[ind].first;
            r = b[ind + 1].second - 1;
        }
        else
        {
            break;
        }


        //cout << "[" << l << "," << r << "] (" << h << ") <- left: " << m - sum << endl;

        if(m - sum == 0)
            break;
    }
    int ans;

    if(((b[ind + 2].second - b[ind + 1].second) + ((m - sum) / (b[ind + 1].first - h))) > r - l + 1)
    {
        ans = ((b[ind + 2].second - b[ind + 1].second) + ((m - sum) / (b[ind + 1].first - h)));
    }
    else
    {
        ans = r - l + 1;
    }
    cout << ans << endl;
    return 0;
}

//---
//wowaka & hitorie collection Pt. 1
//*One Me Two Hearts*
//---