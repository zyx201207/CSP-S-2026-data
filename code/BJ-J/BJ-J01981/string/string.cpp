#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n,cnt,lenth;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        char b;
        cin>>m>>b;
        for(int j=1;j<=m;j++)
        {
            a=a+b;
        }
        lenth+=m;
    }
    for(int i=0;i<=lenth;i++)
    {
        if(a[i]!=a[lenth-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
