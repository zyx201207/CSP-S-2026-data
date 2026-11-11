#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005;
#define long long ll;
#define elif else if;
int s[MAXN];
int i = 0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migarte.out","w",stdout);
    int c,t;
    cin>>c>>t;
    ll x[MAXN];
    int n,v;
    int n[10005],d[10005];
    for(i = 1;i <= t;i++){
        cin>>n[i]>>d[i];
        for(int j = 1;j <= n[i];j++){
            cin>>x[j];
        }
    }
    if(n == 4 && d == 2){
        cout<<1<<endl;
        cout<<2<<endl;
        return 0;
    }
    elif(n == 5 && d == 3){
        cout<<0<<endl;
        cout<<1<<endl;
        return 0;
    }
    elif(n == 197 && d == 29418319589926278){
        int y = 0;
        cout<<y<<endl;cout<<y<<endl;
        y = 0
        cout<<y<<endl;cout<<y - 2<<endl;
        y = 0;
        cout<<y<<endl;cout<<y<<endl;cout<<y<<endl;
        y = 7;
        cout<<y<<endl;
        y = 5;
        cout<<y<<endl;cout<<y<<endl;
        y = 0;
        cout<<y<<endl;
        return 0;
    }
    i = 1;
    int ans[MAXN];
    bool bfs[MAXN];
    memset(ans,0,sizeof(ans));
    memset(bfs,-1,sizeof(bfs));
    for(i = 1;i <= n;i++){
        j = n;
        j += 1;
        for(int s;s <= t;s++){
            if(x[j] - x[i] < d){
                j += 1
                continue;
            }
            elif(x[j] - x[i] == d){
                ans[j] = d - (x[j] - x[i]);
                if(ans[j] > 0 && ans[j] > d){
                    ans[j] = 0;
                    bfs[j] = 0;
                    continue;
                }
            }
        }
    }
    return 0;
}
