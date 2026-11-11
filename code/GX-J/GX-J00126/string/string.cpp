#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    char n[400020];
    int a,k=0,sum=0;
    cin>>a;
    for (int i=0;i<a;i++)
    {
        int l;
        cin>>l;
        sum+=l;
        char b[2];
        cin>>b;
        for (int j=k;j<k+l;j++)
        {
            n[2*j]=b[0];
            k++;
        }
    }
    cout<<sum/2;
    return 0;
}
