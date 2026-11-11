#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],zt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int l=1;l<=n;l++)
    {
        int t[300005]={};
        vector<int>v;
//        cout<<"jushu="<<l<<endl;
        for(int i=l;i<=n;i++)
        {
//            cout<<"card="<<a[i]<<endl<<"v=";
//            for(int j=0;j<v.size();j++)
//            {
//                cout<<v[j]<<" ";
//            }
//            cout<<endl;
            if(t[a[i]]==0)
            {
                t[a[i]]++;
            }
            else
            {
                int bj=0;
                for(int j=v.size()-1;j>=0;j--)
                {
                    int vi=v[j];
                    if(bj==0)
                    {
//                        cout<<vi<<endl;
                        v.pop_back();
                        t[vi]=0;
                    }
                    if(vi==a[i])
                    {
                        t[vi]++;
                        break;
                    }
                }
            }
            v.push_back(a[i]);
//            cout<<"jg=";
//            for(int j=0;j<v.size();j++)
//            {
//                cout<<v[j]<<" ";
//            }
//            cout<<endl<<endl;
        }
        for(int i=0;i<v.size();i++)
        {
            zt[v[i]]++;
        }
//        for(int i=1;i<=m;i++)
//    {
//        cout<<zt[i]<<" ";
//    }
//        cout<<"---------------------------------"<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<zt[i]<<" ";
    }
    return 0;
}
