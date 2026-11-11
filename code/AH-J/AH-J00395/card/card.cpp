#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500020],cnt[300020],cnt2[300020],flag[300020];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    queue<int>t;
    int k=0;
    while(k<n){
        k++;
        for(int i=k;i<=n;i++){
            if(cnt[a[i]]!=0){
                cnt[a[i]]--;
                t.pop();
                while(t.front()!=a[i]){
                    cnt[t.front()]--;
                    t.pop();
                }
            }
            t.push(a[i]);
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            flag[i]=0;
        }
        while(!t.empty()){
            if(!flag[t.front()]){
                cnt2[t.front()]++;
                flag[t.front()]=1;
            }
            t.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt2[i] << ' ';
    }
}
