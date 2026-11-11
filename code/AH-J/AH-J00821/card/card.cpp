#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],cnt[300010],n,m;
vector<LL> v;
bool check(){
    for(LL i=1;i<n;i++){
        if(a[i]>a[i+1]) return 0;
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++) cin>>a[i];
    if(check()){
        for(LL i=1;i<=n;i++) cnt[a[i]]++;
        LL sum=0;
        for(LL i=1;i<=m;i++){
            sum+=cnt[i];
            cout<<sum<<" ";
        }
        return 0;
    }
    for(LL i=1;i<=n;i++){
        v.clear();
        for(LL j=i;j<=n;j++){
            LL pos=-1;
            for(LL k=0;k<LL(v.size());k++){
                if(a[j]==v[k]){
                    pos=k;
                    break;
                }
            }
            if(pos!=-1){
                LL len=LL(v.size());
                for(LL k=len-1;k>=pos;k--) v.pop_back();
                v.push_back(a[j]);
            }
            else v.push_back(a[j]);
        }
        for(LL i=0;i<v.size();i++) cnt[v[i]]++;
    }
    for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
