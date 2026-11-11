#include <bits/stdc++.h>
using namespace std;
int cnt[100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[500100];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    vector<int> tab;
    tab.resize(n+10);
    for (int i=1;i<=n;i++)
    {
        tab.clear();
        for (int j=i;j<=n;j++)
        {
            if(tab.empty()) tab.push_back(a[j]);
            else
            {
                bool f=0;
                int pos=0;
                for (int k=0;k<tab.size();k++)
                {
                    if (tab[k]==a[j])
                    {
                        //cout<<114514;
                        f=1;
                        pos=k;
                        break;
                    }
                }
                if (!f) tab.push_back(a[j]);
                else
                {
                    if (pos==tab.size()) tab.pop_back();
                    else
                    {
                        for (int k=pos;k<=tab.size();k++)
                        {
                            //cout<<114514;
                            tab[k]=-1;
                        }
                        tab.push_back(a[j]);
                    }
                }
            }
        }
        for (int c:tab)
        {
            //cout<<c<<" ";
            if (c!=-1) cnt[c]++;
        }
        //cout<<endl;
    }
    for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
