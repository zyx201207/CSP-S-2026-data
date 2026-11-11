#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n;
    cin>>n;
    char c;
    long long b,cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>b>>c;
        for(int j=0;j<b;j++)
            a+=c;
    }
    for(int i=0;i<a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-i-1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}