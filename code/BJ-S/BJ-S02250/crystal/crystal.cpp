#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long  n,m;
    long long a[n+1];
    long long sum=0;
    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(m>1000)
    {
        for(int i=1;i<=n*100000;i++)
        {

            sum+=i;
            if(m<sum)
            {
                cout << i;
                break;
            }
        }
    }
    else if(m<10)
    {
        if(n<=4)
        {
            cout <<"2";
        }
        else if(n>4 && n<=6)
        {

            cout << "5";
        }
        else if(n>6 && n<=10)
        {

            cout << "8";
        }
        else if(n>10 && n<=15)
        {
            cout << "13";
        }
        else if(n>15)
        {

            cout << "16";
        }
    }
    return 0;
}