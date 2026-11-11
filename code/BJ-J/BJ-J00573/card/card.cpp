#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+5;
int n,m;
int a[N];
int cnt[M];stack <int> pre[M];
int que[N];
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int st = 1;st<=n;st++){
        for(int i = 1;i<=n;i++){
            while(!pre[i].empty())pre[i].pop();
            pre[i].push(-1);
        }
        int t = 0;
        for(int i = st;i<=n;i++){
            que[++t] = a[i];
            if(pre[a[i]].top()>0){
                int temp = pre[a[i]].top();
                for(int j = pre[a[i]].top()+1;j<=t;j++){
                    if(pre[que[j]].top()>0)pre[que[j]].pop();
                }
                t = temp;
            }
            pre[a[i]].push(t);
        }
        //cout<<st<<":";
        for(int j = 1;j<=t;j++){
            //cout<<que[j]<<" ";
            cnt[que[j]]++;
        }
        //cout<<endl;
    }
    for(int i = 1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
