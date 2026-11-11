#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,maxn = -1e9,sum = 0;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i] >> c[i];
        maxn = max(maxn,a[i]);
        sum += a[i];
    }
    if(maxn == 1)
    {
        string s = "";
        for(int i = 1;i <= n;++i)
        {
            s += c[i];
        }
        int mid = (s.size() + 1) / 2;
        int ans = 0;
        if(sum % 2 == 1)
        {
            for(int i = 1;i < mid;++i)
            {
                if(s[mid + i - 1] != s[mid - i - 1])ans++;
            }
            cout << ans;
            return 0;
        }
        else{
            for(int i = 1;i <= mid;++i)
            {
                if(s[mid - i] != s[mid + i - 1])ans++;
            }
            cout << ans;
            return 0;
        }
    }
    if(n <= 2000 && maxn <= 50)
    {
        string s = "";
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= a[i];++j){
                s += c[i];
            }
        }
        int mid = (s.size() + 1) / 2;
        int ans = 0;
        if(sum % 2 == 1)
        {
            for(int i = 1;i < mid;++i)
            {
                if(s[mid + i - 1] != s[mid - i - 1])ans++;
            }
            cout << ans;
            return 0;
        }
        else{
            for(int i = 1;i <= mid;++i)
            {
                if(s[mid - i] != s[mid + i - 1])ans++;
            }
            cout << ans;
            return 0;
        }
    }
    int l = 1,r = n;
    long long pro = 0;
    while(l < r)
    {
        if(a[l] < a[r])
        {
            if(c[l] != c[r])pro += a[l];
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
        else if(a[l] > a[r])
        {
            if(c[l] != c[r])pro += a[r];
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }
        else if(a[l] == a[r])
        {
            if(c[l] != c[r])pro += a[r];
            a[l] = 0;
            a[r] = 0;
            r--;
            l++;
        }
    }
    cout << pro;
    return 0;
}