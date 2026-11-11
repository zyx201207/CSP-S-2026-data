#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005];
bool flag[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool flagsort=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flagsort=false;
    }
    if(flagsort){
        int num[200005];
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            num[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<num[i]<<" ";
        }
        return 0;
    }
    stack<int>q;
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        for(int j=i;j<=n;j++){
            if(flag[a[j]]){
                while(!q.empty()){
                    if(q.top()==a[j]){
                        break;
                    }
                    flag[q.top()]=0;
                    q.pop();
                }
            }
            else{
                flag[a[j]]=1;
                q.push(a[j]);
            }
        }
        while(!q.empty()){
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
