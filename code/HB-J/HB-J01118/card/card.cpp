#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
set<int>s;
stack<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cnt[a[i]]+=i;
    for(int i=1;i<=n;i++){
        s.clear();
        for(int j=i;j<=n;j++){
            if(s.count(a[j])==0){
                s.insert(a[j]);
                q.push(a[j]);
            }
            else{
                while(q.top()!=a[j]){
                    cnt[q.top()]--;
                    q.pop();
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
    return 0;
}