#include<bits/stdc++.h>
using namespace std;
struct node{
    int jg;
    int bq;
};
int c,n,m,di,q,k,w[500005];
int a[500005],t[500005];
vector<node>v[500005];
int d[500005],bj[500005];
int dis(int s,int e)
{
//    cout<<s<<" "<<e<<endl<<endl;
    for(int i=0;i<v[s].size();i++)
    {
        d[v[s][i].jg]=v[s][i].bq;
    }
    d[s]=0,bj[s]=1;
    int cnt=1;
//        for(int ii=1;ii<=m;ii++)
//        {
//            cout<<d[ii]<<" ";
//        }
//        cout<<endl<<endl;
//        for(int ii=1;ii<=m;ii++)
//        {
//            cout<<bj[ii]<<" ";
//        }
//        cout<<endl;
    while(cnt<m)
    {
        int mins=INT_MAX,mini=0;
        for(int i=1;i<=m;i++)
        {
            if(mins>=d[i]&&bj[i]==0)
            {
                mins=d[i];
                mini=i;
            }
        }
        if(mini==e) return mins;
        for(int i=0;i<v[mini].size();i++)
        {
            if(i!=mini&&bj[v[mini][i].jg]==0)
            {
                d[v[mini][i].jg]=min(mins+v[mini][i].bq,d[v[mini][i].jg]);

            }
//            for(int ii=1;ii<=m;ii++)
//                {
//                    cout<<d[ii]<<" ";
//                }
//                cout<<endl<<endl;
//                for(int ii=1;ii<=m;ii++)
//                {
//                    cout<<bj[ii]<<" ";
//                }
//                cout<<endl;
        }
        bj[mini]=1;
        cnt++;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>di>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
        }
//        for(int j=1;j<=k;j++)
//        {
//           cout<<t[j]<<" ";
//        }
//        cout<<endl;
        for(int ii=1;ii<=k;ii++)
        {
            for(int jj=1;jj<=k;jj++)
            {
                int s=a[ii],e=a[jj];
//                cout<<s<<" "<<e<<" "<<t[s]<<" "<<t[e]<<endl;
                int starti,endi;
                for(int ij=1;ij<=k;ij++)
                {
                    if(a[ij]==s) starti=ij;
                    if(a[ij]==e) endi=ij;
                }
                v[s].push_back({e,t[starti]+t[endi]});
            }
        }
    }
//    for(int j=1;j<=m;j++)
//    {
//        for(int i=0;i<=v[j].size();i++)
//    {
//        cout<<v[j][i].jg<<" "<<v[j][i].bq<<endl;
//    }
//    cout<<"-----------------------------------"<<endl;
//    }

    for(int i=1;i<=q;i++)
    {
        memset(d,0x3f,sizeof(d));
        memset(bj,0,sizeof(bj));
        int st,en;
        cin>>st>>en;
        cout<<w[st]+dis(st,en)+w[en]<<endl;
    }
    return 0;
}
