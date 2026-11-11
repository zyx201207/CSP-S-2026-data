#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005],b[300005],c[500005],s,f1[500005],s1;
bool f[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int z=1;z<=n;z++){
        for(int i=z;i<=n;i++){
            s++;
            if(f[a[i]]==0){
                f[a[i]]=1;
                f1[a[i]]=s;
                c[s]=a[i];
            }else{
                s-=s-f1[a[i]];
                for(int j=f1[a[i]]+1;j<=s;j++){
                    f[a[j]]=0;
                    c[j]=-1;
                }
                c[f1[a[i]]]=a[i];
            }

        }
        for(int i=1;i<=s;i++){
            if(f[c[i]]==1){
            b[c[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            f[i]=0;
            f1[i]=0;
            c[i]=0;
        }
        s=0;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
