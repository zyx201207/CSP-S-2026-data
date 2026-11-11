#include <iostream>

using namespace std;
string s;
char a[200100]= {0};
int bx(int a)
{
    int n=1;
    if(a%10==0)
    {
        a/=10;
        n*=10;
        a=bx(a);
    }
    else
        return a;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m=0,w=0,f=0,m2=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>m>>a[i];
        m2=bx(m);
        for(int j=0; j<m2; j++)
        {
            s+=a[i];
        }
        w+=m2;
    }
    int j=w-1;
    for(int i=0; i<=j; i++)
    {
        if(s[i]!=s[j])
        {
            f++;
        }
        j--;
    }
    cout << f *m/m2;
    return 0;
}
