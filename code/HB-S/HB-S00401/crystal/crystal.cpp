#include <bits/stdc++.h>
using namespace std;

int nmao,bmao;
long long mmao,amao[100005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> nmao >> mmao;
    for(int i=1;i<=nmao;i++)
    {
        cin >> amao[i];
    }
    sort(amao+1,amao+nmao+1);
    for(int i=2;i<=nmao;i++)
    {
        long long qumao=0;
        for(int j=1;j<i;j++)
        {
            qumao+=amao[i]-amao[j];
        }
        if(qumao<=mmao)
        {
            bmao=i;
        }
        else  break;
    }
    cout << bmao;
    return 0;
}
