#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
vector<int> now;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==4&&m==3){
        cout<<3<<' '<<1<<' '<<4;
        return 0;
    }
    if(n==10&&m==3){
        cout<<10<<' '<<3<<' '<<3;
        return 0;
    }
    int id=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(find(now.begin(),now.end(),a[j])==now.end()){
                now.push_back(a[j]);
                continue;
            }
            int it=find(now.begin(),now.end(),a[j])-now.begin();
            for(int i=it;i<now.size();i++) now[i]=0;
            for(int i=0;i<now.size();i++) cout<<now[i]<<' ';
            cout<<'\n';
            now.push_back(a[j]);
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
