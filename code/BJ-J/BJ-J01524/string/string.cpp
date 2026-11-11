#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
string c[N],b;
bool hw(string c)
{
    int x=0;
    int y=c.size();
    for(int i=0;i<=y/2;i++)
    {
        if(c[x]!=c[y])
        {
            return 0;
        }
        x++,y--;
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=;i++)
    {
        cin>>a[i]>>c[i];
        if(i==0)
        {
            
        }
    }
    return 0;
}
