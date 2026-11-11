#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
bool v[300005];
vector<int>p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        memset(v,0,sizeof(v));
        for(int j=i;j<=n;j++){
            if(!v[a[j]])p.push_back(a[j]),v[a[j]]=1;
            else{
                int k;
                for(k=0;k<p.size();k++)if(p[k]==a[j])break;
                int m=k;
                for(;k<p.size();k++)v[p[k]]=0,p[k]=0;
                p[m]=a[j];
                v[a[j]]=1;
            }
        }
        for(int j=0;j<p.size();j++)cnt[p[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
