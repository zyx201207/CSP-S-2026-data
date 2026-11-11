#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],cnt[500005];
vector<int>v;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        v.clear();
        for(int j=i;j<=n;j++){
            int id=-1;
            for(int k=0;k<v.size();k++){
                if(v[k]==a[j]){
                    id=k;
                    break;
                }
            }
            if(id!=-1) for(int k=id;k<v.size()+2;k++) v.pop_back();
            v.push_back(a[j]);
        }
        for(int k=0;k<v.size();k++){
            cnt[v[k]]++;
            //cout<<v[k]<<' ';
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
