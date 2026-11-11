#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int a[N],h[N],hax[N];
set<int> st;
stack<int>q;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        memset(hax,0,sizeof(hax));
        for(int j = i;j<=n;j++){
            if(!hax[a[j]]){
                q.push(a[j]);
                hax[a[j]] = 1;
            }else{
                while(1){
                    if(q.top() == a[j]){
                        break;
                    }
                    hax[q.top()] = 0;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            int cur = q.top();
            q.pop();
            h[cur]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout << h[i] << ' ';
    }
    return 0;
}
