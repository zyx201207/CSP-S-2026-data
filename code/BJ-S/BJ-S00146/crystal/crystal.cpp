#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;


int a[N];
int n,m,k,ans;
int zs;
int szs;

signed main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,[](const int i,const int j){return i>j;});
    for(int i=1;i<=n;i++){
        k=0;
        bool ok=1;
        int nn=a[i];
        for(int j=i;j<=n;j++){
            k+=abs(min(nn,a[j])-max(nn,a[j]));
            if(k>=m){
                if(j!=n||k>m||(j==n&&k>m)){
                    ok=0;
                    break;
                }
                break;
            }

        }
        if(k<=m&&ok){
            for(int k=1;k<=n;k++){
                if(a[i]>=a[k])ans++;
                //cout<<"a[i]:"<<a[i]<<"a[k]:"<<a[k]<<"ok:"<<(bool)(a[i]>=a[k])<<endl;
            }
            return cout<<ans,0;
        }
    }
    return 0;
}
