#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[500010],k=1,lp,mn[500002],u=1,hg[500001],jk=1,byr=0,mj,er,gyc=0,pu=1,ovo[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ans[i];

    }
    sort(ans,ans+n);
    for(int i=1;i<=n;i++){
        if(ans[i]==ans[i-1]){
            lp=ans[i];
            k++;
            if(ans[i+1]!=ans[i]){
                mn[u]=k;
                k=1;
                u++;
                hg[jk]=lp;
                lp=0;
                jk++;
            }
        }
    }
    for(int i=1;i<=u-1;i++){
        for(int j=1;j<=u-1;j++){
            if(mn[i]>=mn[j]){
                byr++;
            }
        }
        if(byr==u-1){
            mj=hg[i];
            er=mn[i];
            i=u;

        }
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<=n-j-1;i++){
            if(gyc<m){
                gyc+=ans[n-j]-ans[n-i-j];
                pu++;
            }else if(gyc>m){
                pu--;
                ovo[j+1]=pu;
                i=n-j-1;
            }
            else{
                i=n-j-1;
                ovo[j+1]=pu;
            }
            if(i==n-j-1&&gyc<=m&&ovo[j+1]==0){
                ovo[j+1]=pu;
            }else if(i==n-j-1&&gyc>m&&ovo[j+1]==0){
                pu--;
                ovo[j+1]=pu;
            }
        }
        pu=1;
        gyc=0;
    }
    sort(ovo,ovo+n);
    if(m==0){
        cout<<er;
    }else{
        cout<<ovo[n-1];
    }

    return 0;
}
