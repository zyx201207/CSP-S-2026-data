#include<bits/stdc++.h>
using namespace std;
vector <char>s;
long long n,sum=0;
int main()
{
    cin>>n;
    freopen("string.in","r"stdin);
    freopen("string.out","w"stdout);
    for(int i=1;i<=n;i++)
    {
        char b;
        int a;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s.push_back(b);
        }
    }
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            sum++;
        }
        //cout <<s[i];
    }
    cout <<sum/2;
    return 0;
}
