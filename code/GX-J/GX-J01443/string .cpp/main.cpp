#include<bits/stdc++.h>

using namespace std;
long long n,a,sum,x;
char c;
string s,b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>c;
        for(int j=0; j<a; j++)
        {
            s+=c;
        }
    }
    x=s.size();
    if(x%2==0)
    {
        for(int i=0; i<x/2; i++)
        {
            b="";
            for(int j=x-1; j>=0; j--)
            {
                b+=s[j];
            }
            if(s==b)
            {
                cout<<sum;
                return 0;
            }
            if(s[i]!=s[x-i-1])
            {
                s[i]=s[x-i-1];
                sum+=1;
            }

        }
    }
    else if(x%2==1)
    {
        for(int i=0;x/2+1; i++)
        {
            b="";
            for(int j=x-1; j>=0; j--)
            {
                b+=s[j];
            }
            if(s==b)
            {
                cout<<sum;
                return 0;
            }
            if(s[i]!=s[x-i-1])
            {
                s[i]=s[x-i-1];
                sum+=1;
            }


        }
    }
}
