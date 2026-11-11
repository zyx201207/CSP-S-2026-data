#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int _,T;
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>_>>T;
    while(T--)
    {
        cin>>n>>m;
        cout<<((n-1)/2/2-m/2+1)/2+1<<"\n";
    }
    return 0;
}