#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,nowx,cnt,ti;
    cin >> c >> t;
    while(t--){
        cnt=0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        for(int u = 1;u <= n;u++){
            for(int v = 1;v <= n&&u<v;v++){
                int mincnt=1e9,tcnt=0,lti;
                nowx=x[u];
                lti=u;
                while(x[v]>nowx){//forward to next island
                    tcnt++;
                    if(x[v]-nowx<=d) break;
                    ti=u;
                    while(nowx+x[ti]<x[ti+1]) ti++;
                    nowx=x[ti];
                }
                if(tcnt>mincnt) break;
                else if(tcnt<mincnt) mincnt=tcnt;
                else if(tcnt==mincnt) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
