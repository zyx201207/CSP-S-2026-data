#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ni=0;
        cin>>ni;
        char so;
        cin>>so;
        for(int j=0;j<ni;j++)
        {
            s+=so;
        }
    }
    //cout<<s<<endl;
    string z="";
    if(s.size()%2==0)
    {
        long long f=0;
        for(int i=0;i<s.size()/2;i++)
        {
            z+=s[i];
        }
     //   cout<<z<<endl;
        int ii=1;
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(s[i]==z[s.size()/2-ii])
            {
                f++;
            }
            ii++;
        }
     //   cout<<f<<endl;
        cout<<s.size()/2-f;
    }else
    {
        long long f=0;
        for(int i=0;i<s.size()/2;i++)
        {
            z+=s[i];
        }
     //   cout<<z<<endl;
        int ii=1;
        for(int i=s.size()/2+1;i<s.size();i++)
        {
            if(s[i]==z[s.size()/2-ii])
            {
                f++;
            }
            ii++;
        }
     //   cout<<f<<endl;
        cout<<s.size()/2-f;
    }
    return 0;
}
