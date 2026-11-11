#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<long long> cnt(m+1,0);
    queue<int> q,q2;
    for(int i=1;i<=n;i++){
        vector<bool> used(m+1,false);
        for(int j=i;j<=n;j++){
            if(used[a[j]]){
                while(!q.empty()){
                    if(q.front()==a[j]){
                        q.pop();
                        break;
                    }
                    q2.push(q.front());
                    q.pop();
                }
                while(!q.empty()){
                    used[q.front()]=false;
                    q.pop();
                }
                while(!q2.empty()){
                    q.push(q2.front());
                    q2.pop();
                }
                q.push(a[j]);
            }else{
                q.push(a[j]);
                used[a[j]]=true;
            }
        }
        while(!q.empty()){
            cnt[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
