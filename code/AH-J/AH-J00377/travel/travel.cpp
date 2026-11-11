#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d;
    string e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a==c) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b==d) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((e=="A"&&(f=="B"||f=="C"))||(e=="B"&&(f=="A"||f=="C"))||(e=="C"&&(f=="A"||f=="B"))||(e=="D"&&f=="F")||(e=="F"&&f=="D")) cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if((e=="A"&&f=="B")||(e=="B"&&f=="C")||(e=="D"&&f=="F")||(e=="F"&&f=="D")) cout<<1;
    else cout<<0;
}
