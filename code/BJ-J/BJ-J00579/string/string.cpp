#include<bits/stdc++.h>
using namespace std;

struct add
{
    long long sum;
    char zf;
}a[200100];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt= 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i].sum >> a[i].zf;
    }
    long long i = 0,j = n-1;
    while(i < j)
    {
        if(a[i].zf == a[j].zf)
        {
            if(a[i].sum > a[j].sum)
            {
                a[i].sum -= a[j].sum;
                a[j].sum = 0;
                j--;
            }
            else if(a[i].sum < a[j].sum)
            {
                a[j].sum -= a[i].sum;
                a[i].sum = 0;
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if(a[i].sum > a[j].sum)
            {
                a[i].sum -= a[j].sum;
                cnt+=a[j].sum;
                a[j].sum = 0;
                j--;
            }
            else if(a[i].sum > a[j].sum)
            {
                a[j].sum -= a[i].sum;
                cnt += a[i].sum;
                a[i].sum = 0;
                i++;
            }
            else
            {
                cnt += a[i].sum;
                i++;
                j--;
            }
        }
    }
    cout << cnt;
    return 0;
}
