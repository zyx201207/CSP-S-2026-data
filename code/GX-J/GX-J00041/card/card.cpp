#include <bits/stdc++.h>
using namespace std;
int a[500010];
queue <int> q;
int ans[500100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=0;
    for (int i=1;i<=n;i++){
        for (int k=i;k<=n;k++){
            while (!q.empty() && a[q.front()]==a[k]){
                for (int j=1;j<=k-q.front();j++) {
                    q.pop();
                    num++;
                }
            }
            q.push(k);
        }
    }
    for (int i=1;i<=n-num;i++){
        cout<<a[q.front()]<<" ";
        q.pop();
    }
    return 0;
}
