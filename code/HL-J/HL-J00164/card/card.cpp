#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],f[100000],cnt[100000];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[j]==0){
                f[a[j]]=1;
                q.push_back(a[j]);
            }else{
                for(int z=q.size();z>=0;z--){
                    if(q[z]==f[a[j]]){
                        continue;
                    }
                    f[q.back()]=0;
                    q.pop_back();
                }
                q.push_back(a[j]);
                f[a[j]]=1;
            }
        }
        for(int h = 0;h<=q.size();h++){
            cnt[q.front()]++;
            q.pop_front();
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
