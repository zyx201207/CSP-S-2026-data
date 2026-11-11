#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],box[300005];
vector <int> d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int len=n;len>0;len--){
            d.clear();
        if(len==n){
            box[a[n]]++;
            continue;
        }
        for(int i=len;i<=n;i++){
            int flag=d.size(),dsize=d.size();
            for(int j=0;j<dsize;j++){
                if(a[i]==d[j])
                    flag=j;
            }
            d.erase(d.begin()+flag,d.end());
            d.push_back(a[i]);
        }
        for(int i=0;i<d.size();i++){
            box[d[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<box[i]<<" ";
    return 0;
}