#include<bits/stdc++.h>
using namespace std;
struct nums
{
    int num;
    char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    long long sum=0;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].num >> a[i].c;
        for(int j=1; j<=a[i].num; j++)
        {
            s+=a[i].c;
        }
    }
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
           s[s.size()-i-1]=s[i];
           sum++;
        }
    }
    cout << sum;
    return 0;
}
