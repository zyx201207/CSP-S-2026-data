#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin >> n >> m;
    int  a,sum=0;
    string l;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        l[i] = a;
    }
    int s;
    s = l.size();
    for(int i=1;i<s-1;i++)
    {
        sum = l[0] and l[1];
        if((l[i] and l[i+1]) > sum)
        {
            sum = l[i] and l[i+1];
        }
    }
    cout << sum;
    return 0;
}

