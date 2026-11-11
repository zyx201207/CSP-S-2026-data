#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    vector<vector<int>> t(n),a(m),A(n);
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a1,t1;
            cin>>a1>>t1;
            a1--;
            a[a1].push_back(i);//站点
            A[i].push_back(a1);//路径
            t[i].push_back(t1);
        }
    }
    for(int i=0;i<q;i++)
    {
        int be,en;
        cin>>be>>en;
        be--;
        en--;
        vector<int> tmp(m,INT_MAX);
        vector<int> zong(m,0);
        vector<bool> used(m,false);
        //used[be]=true;
        tmp[be]=0;
        int tp=0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<A[j].size();k++)
            {
                if(A[j][k]==be)
                {
                    tp=j;
                    break;
                }
            }
        }
        zong[be]=tp;
        for(int j=0;j<m-1;j++)
        {
            int in1=0,in2=INT_MAX;
            for(int k=0;k<m;k++)
            {
                if(in2>=tmp[k]&&used[k]!=true)
                {
                    in1=k;
                    in2=tmp[k];
                }
            }
            used[in1]=true;
            for(int k=0;k<(int)a[in1].size();k++)
            {
                for(int o=0;o<(int)A[a[in1][k]].size();o++)
                {
                    if(used[A[a[in1][k]][o]]!=true)
                    {
                        if(tmp[A[a[in1][k]][o]]>tmp[in1]+t[zong[in1]][in1]+t[k][o])
                        {
                            tmp[A[a[in1][k]][o]]=tmp[in1]+t[zong[in1]][in1]+t[k][o];
                            zong[in1]=k;
                        }
                    }
                }
            }
        }
        cout<<tmp[en]+w[be]+w[en]<<endl;
    }
    return 0;
}