#include<bits/stdc++.h>
using namespace std;

struct line{
    long long num;
    int a[500000+10];
    int t[500000+10];
    bool visl=0;
}l[500+10];

vector<int> p1[500000+10];
vector<int> p2[500000+10];
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);



    int sz[500000+10];
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    int tt[500000+10];
    for(int i=1;i<=m;i++){
        cin>>tt[i];
}

    for(int i=1;i<=n;i++){

        int k;
        cin>>k;
        l[i].num=k;
        for(int j=1;j<=k;j++){
            cin>>l[i].a[j]>>l[i].t[j];
            p1[l[i].a[j]].push_back(i);
            p2[l[i].a[j]].push_back(l[i].t[j]);
            sz[l[i].a[j]]++;
        }
    }

    for(long long r=1;r<=q;r++){
        for(int i=0;i<510;i++){
            l[i].visl=0;
        }
        bool vis[500000+10]={0};
        long long x,y;
        cin>>x>>y;
        int ans=0,tx[500000+10]={0};
        queue<long long>q;
        q.push(x);
        vis[x]=1;
        int xxx=100;
        while(!q.empty()){
            int root=q.front();
            q.pop();
            for(int i=0;i<sz[root];i++){
                    if(l[p1[root][i]].visl==1)continue;
                    l[p1[root][i]].visl=1;
                for(int j=1;j<=l[p1[root][i]].num;j++){
               // cout<<l[p1[root][i]].a[j]<<' ';
                    if(vis[l[p1[root][i]].a[j]]==0){
                        vis[l[p1[root][i]].a[j]]=1;
                        q.push(l[p1[root][i]].a[j]);
                        int add=tx[root]+l[p1[root][i]].t[j]+p2[root][i];
                        tx[l[p1[root][i]].a[j]]=add;
                 //       cout<<l[p1[root][i]].a[j]<<'a'<<l[p1[root][i]].t[j]<<'b'<<p2[root][i]<<' ';

                    }
                }
            }
        }
        cout<<tx[y]+tt[x]+tt[y]<<endl;
       // for(int i=1;i<=m;i++){
      //      cout<<tx[i]<<' ';
       // }
      //  cout<<endl;
    }
  //  for(int i=1;i<=m;i++){
   //     for(int j=0;j<p1[i].size();j++){
   //         cout<<p1[i][j]<<' ';
  //      }
   //     cout<<'\n';
   // }



    return 0;
}
