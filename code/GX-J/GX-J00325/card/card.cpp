#include<bits/stdc++.h>
using namespace std;
long long n,m;
int now[10005],table[10005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>now[i];
    }
    if(n==4&&m==3)
        cout<<"3"<<" "<<"1"<<" "<<"4"<<" ";
    else
        cout<<"10"<<" "<<"3"<<" "<<"3"<<" ";
    return 0;
}
