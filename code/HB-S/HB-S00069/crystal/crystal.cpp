#include<bits/stdc++.h>
using namespace std;
vector<int > a;
int check(int x,int sum)
{

    int cnt =0;
    for(int i = x;i >= 0;i--)
    {
        if(sum >= abs(a[x] - a[i]))
        {
            sum -= abs(a[x] - a[i]);
            cnt++;
        }
        else
            return cnt;
    }
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >>n>>m;
    for(int i =1;i <= n;i++)
    {
        int h;
        cin >>h;
        a.push_back(h);
    }
    long long l = 1,r =n,max = 1;

    for(int i =1;i < n;i++)
    {
        if(check(i,m) > max)
        {
            max = check(i,m);
        }
    }
    cout <<max;

    return 0;
}
