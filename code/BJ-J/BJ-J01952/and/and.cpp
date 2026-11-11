#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
bool cmp(int a,int b)
{
    return(a>b);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    int sum = v[0];
    for(int i = 1;i < m;i++) sum &= v[i];
    cout << sum;
    return 0;
}
