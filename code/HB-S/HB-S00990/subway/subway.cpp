#include <bits/stdc++.h>

using namespace std;
map<int,int>p[505];
map<int,int>w[505];
map<int,int>f[505];
map<int,int>flag;

long long c,num,n,d,a[500005],b[500005],k;
struct node {
      long long x,w;
};
queue <node>q;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>num>>d>>k;
    for(int i=1;i<=num;i++){
        cin>>b[i];file:

        flag[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=a[i];j++)
        {
            cin>>p[i][j]>>w[i][j];
            f[i][p[i][j]]=j;
        }

    }
    node t;
    t.x=1;
    t.w=0;
    q.push(t);
    flag[1]=0;
    while(!q.empty()){
        node tt=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(f[i][tt.x]!=0){
                for(int j=1;j<=a[i];j++)
                {
                    if(p[i][j]!=tt.x){
                      long long dx=tt.x;
                      long long dy=p[i][j];
                      if(flag[dy]>tt.w+w[i][j]+w[i][f[i][tt.x]]){
                            flag[dy]=tt.w+w[i][j]+w[i][f[i][tt.x]];
                            node ts;
                            ts.x=p[i][j];
                            ts.w=flag[dy];
                            q.push(ts);
                        }

                    }
                }
            }
        }
    }
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        cout<<flag[y]-flag[x]+b[x]+b[y]<<endl;
    }
}
