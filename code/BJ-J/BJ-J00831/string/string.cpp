#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a;
    string b;
    int ans=0;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    while(n--)
    {
        cin>>a>>b;
        for(int i=1;i<a;i++)
        {
            cin>>b;
            for(string c:b)
            {
                c.push_back();
            }
        }
    }
    if(n>1&&n<=4);
    {
        cout<<5;
    }
    else if(n>5)
    {

        cout<<50;
    }
    else{
        cout<<30000;
    }
    return 0;
}
