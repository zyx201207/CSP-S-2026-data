#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<=500){
        for(int i=1;i<=n;i++){
            vector<int>v;
            for(int j=i;j<=n;j++){
                int sz=v.size(),ans=-1;
                for(int k=0;k<sz;k++){
                    if(v[k]==a[j]){
                        ans=k;
                        break;
                    }
                }
                if(ans!=-1)v.erase(v.begin()+ans,v.end());
                v.push_back(a[j]);
            }
            for(int j=0;j<v.size();j++){
                //cout<<v[j]<<' ';
                cnt[v[j]]++;
            }
            //cout<<'\n';
        }
        for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
        return 0;
    }
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1])cout<<cnt<<' ';
        cnt++;
    }
    cout<<cnt<<' ';
    cnt=1;
    return 0;
}
