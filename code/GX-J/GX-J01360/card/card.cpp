#include<bits/stdc++.h>
using namespace std;
vector <int> s;
int n,m,b[300005],sum=0;
int main()
{
    cin>>n>>m;
    freopen("card.in","r"stdin);
    freopen("card.out","w"stdout);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        s.push_back(a);
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            b[s[j]]++;
            if(s[i]==s[j])
            {
                for(int z=i;z<=j-1;z++)
                {
                   b[s[z]]--;
                }
            }
        }
        //b[s[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
       cout <<b[i]<<" ";
    }
  //  cout <<sum;
    return 0;
}
