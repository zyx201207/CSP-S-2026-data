#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<int> cnt;
void f(int x)
{
    vector<int> z;
    for(int i=x;i<n;i++)
    {
        for(int j=0;j<z.size();j++)
        {
            if(z[j]==a[i])
            {
                int u=z.size();
                for(int k=j;k<u;k++)
                {
                    z.erase(z.end()-1);
                }
                break;
            }
        }
        z.push_back(a[i]);
    }
    for(int i=0;i<z.size();i++)
    {
        cnt[z[i]]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++)cnt.push_back(0);
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        a.push_back(o);
    }
    for(int i=0;i<n;i++)
    {
        f(i);
    }
    for(int i=0;i<m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
