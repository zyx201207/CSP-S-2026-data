#include <bits/stdc++.h>
using namespace std;
struct A{
    int i,t;
};
struct Point {
    int k=0;
    int l[25];
};
int c, n, m, d, q;int w[500005];A a[505][25];int dp[500005];Point p[500005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        a[i][0].i=k;
        for(int j=1;j<=k;j++){
            int o,t;
            cin>>o>>t;
            a[i][j].i=o;
            a[i][j].t=t;
            p[o].k++;
            p[o].l[p[o].k]=i;
        }
    }//cout<<1;
    for(int i=1;i<=q;i++){
        int in,out;cin>>in>>out;
        memset(dp,0,sizeof(dp));
        dp[in]=w[in];
        queue<int> q;
        q.push(in);
        while (!q.empty()){
            for(int j=1;j<=p[q.front()].k;j++){
                for(int e=1;e<=a[p[q.front()].l[j]][0].i;e++){
                    int temp;
                    for(int f=1;f<=a[p[q.front()].l[j]][0].i;f++){
                        if (a[p[q.front()].l[j]][f].i==q.front()){
                            temp=a[p[q.front()].l[j]][f].t;
                        }
                    }
                    if((dp[a[p[q.front()].l[j]][e].i]>dp[q.front()]+a[p[q.front()].l[j]][e].t+temp)||dp[a[p[q.front()].l[j]][e].i]==0){

                        dp[a[p[q.front()].l[j]][e].i]=dp[q.front()]+a[p[q.front()].l[j]][e].t+temp;
                        q.push(a[p[q.front()].l[j]][e].i);
                        //cout<<'1'<<' '<<q.front()<<' '<<p[q.front()].k<<' '<<a[p[q.front()].l[j]][e].i<<' '<<dp[a[p[q.front()].l[j]][e].i]<<endl;
                    }
                }
            }
            q.pop();
        }
        cout<<dp[out]+w[out]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
