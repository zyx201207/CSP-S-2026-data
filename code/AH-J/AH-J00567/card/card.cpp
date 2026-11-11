#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],f[M],ans[N];
int  Q[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }


    memset(ans,0,sizeof(ans));

    for(int i=1;i<=n;i++)
    {
       memset(f,0,sizeof(f));
       memset(Q,0,sizeof(Q));
        int top=0;
        for(int j=i;j<=n;j++)
        {
          //  cout<<f[a[j]]<<" "<<top<<Q[top];
            if(f[a[j]]>=1)
            {
              //cout<<Q.top()<<" "<<a[j]<<" ";
              if(Q[0]==a[j]) top=1;
              else{
               while(Q[top-1]!=a[j]) top--;
               }
             // cout<<top<<'\n';
               // cout<<Q[top-1]<<'\n';
               //cout<<Q.top()<<" "<<Q.size()<<"|";
            }
            else{
                f[a[j]]++;
                top++;
                Q[top-1]=a[j];
            }


        }
        for(int t=0;t<top;t++)
        {
       //   cout<<Q[t]<<" ";
            ans[Q[t]]++;
        }
      //cout<<'\n';
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
