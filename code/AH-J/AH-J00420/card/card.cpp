#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
vector<int> v(N),cnt(N);

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> inl(n+1,0);
        deque<int> dq;
       for(int j=i;j<=n;j++){
            if(inl[v[j]]==1){
                while(dq.back()!=v[j]){
                    int a=dq.back();
                    dq.pop_back();
                    inl[a]=0;
                }
            }else{
                dq.push_back(v[j]);
                inl[v[j]]=1;
            }
       }
       while(!dq.empty()){
            cnt[dq.back()]++;
            dq.pop_back();
       }
    }

    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
