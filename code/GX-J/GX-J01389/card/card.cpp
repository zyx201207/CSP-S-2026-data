#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010];
vector <int> now;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        vector <int> v(m);
        v[a[i]]=i;
        now.push_back(a[i]);
        for(int j=i+1;j<=n;j++){
            if(v[a[j]]){
                for(int k=v[a[j]];k<j;k++) now.pop_back();
            }
            now.push_back(a[j]);
            v[a[j]]=j;
        }
        for(int j:now) cnt[j]++;
        now.clear();
    }
    cnt[a[n]]++;
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
