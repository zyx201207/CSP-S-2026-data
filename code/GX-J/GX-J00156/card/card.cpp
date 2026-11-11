#include<bits/stdc++.h>
using namespace std;
int a,b;
int d[500005];
int ans[300005];
int last[300005];
int wz[500005];
bool m[300005];
vector<int> zm;
queue<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>d[i];
    }
    for(int i=1;i<=a+1;i++)
    {
        while(!zm.empty())
        {
            ans[zm[zm.size()-1]]++;
            m[zm[zm.size()-1]]=0;
            zm.pop_back();
        }
        if(i==a+1) break;
        for(int j=i;j<=a;j++)
        {
            if(m[d[j]]==1)
            {
                while(!zm.empty() and zm[zm.size()-1]!=d[j])
                {
                    m[zm[zm.size()-1]]=0;
                    zm.pop_back();
                }
            }
            else
            {
                m[d[j]]=1;
                zm.push_back(d[j]);
            }
            //for(int ii=0;ii<zm.size();ii++) cout<<zm[ii]<<" ";
            //cout<<"\n";
        }
        //cout<<"\n";
    }
    for(int i=1;i<=b;i++) cout<<ans[i]<<" ";
    return 0;
}
