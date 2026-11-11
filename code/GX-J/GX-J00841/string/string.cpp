#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    char b,c;
    string s;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cin>>a>>b;
        if(i==0)
        {
            b=c;
        }
        for(int j=0; j<=a; i++)
        {
            s+=b;
        }
    }
    if(n==1)
    {
        cout<<"0"<<endl;
    }
    if(n==2)
    {
        if(b==c)
        {
            cout<<"0"<<endl;
        }
        else if(b<=c)
        {
            cout<<"1"<endl;
        }
    }

}
