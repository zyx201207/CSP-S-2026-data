#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    string c;
    cin>>n;
    string l;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a >> c;
        for(int j=1;j<=a;j++)
        {

            l += c;
        }
    }
    int s;
    s = l.size();
    for(int i=0;i<=s;i++)
    {if(l[s-1-i] == l[i])
            {
                sum--;
            }
        l[s-1-i] = l[i];
        sum++;

    }
    cout << sum;
    return 0;
}
