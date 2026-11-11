#include<bits/stdc++.h>
using namespace std;
long long n,m,c;
char g;
string a;
void jia(long long b,char d)
{
    string c;
    c+=d;
    while(b)
    {
        if(b%2)
            a+=c;
        b/=2;
        c+=c;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>m>>g;
        jia(m,g);
    }
    for(int i=0,j=a.size()-1;i<j;i++,j--)
        if(a[i]!=a[j])
            c++;
    cout<<c;
    return 0;
}