#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int cnt[300005],d[500005],a[500005];
    for(int i=0;i<=500004;i++){
        cnt[i]=0;
        d[i]=0;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;){
        for(int j=n-i+1;j<=n;){
            bool find=false;
            int k;
            for(k=j+1;k<=n;k++){
                if(a[k]==a[j]&&k<=n){
                    find=true;
                    break;
                }
            }
            if(find==true){
                for(int ii=j;ii<k;ii++){
                    d[ii]=-1;
                }
                j=k;
            }else{
                j++;
            }
        }
        for(int l=n-i+1;l<=n;l++){
            if(d[l]!=-1){
                cnt[a[l]]++;
            }else{
                d[l]=0;
            }
        }
        i--;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
