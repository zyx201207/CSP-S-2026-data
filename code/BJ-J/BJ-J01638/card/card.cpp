#include<bits/stdc++.h>;
using namespace std;
int ac[500005],cnt[300005],zh[500005];
int ab[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ab[i];
    }
    for(int i=1;i<=n;i++){
        memset(zh,0,sizeof(zh));
        memset(ac,0,sizeof(ac));
        int nn=0,zz=0;
        for(int j=i;j<=n;j++){
            nn++;
            ac[nn]=ab[j];
        }
        while(nn!=0){
            for(int j=1;j<=zz;j++){
                if(zh[j]==ac[1]){
                    for(int k=j;k<=n;k++){
                        zh[k]=0;
                    }
                    zz-=j;
                }
            }
            zz+=1;
            zh[zz]=ac[1];
            for(int j=1;j<nn;j++){
                ac[j]=ac[j+1];
            }
            ac[nn]=0;
            nn-=1;
        }
        for(int j=1;j<=zz;j++){
            cnt[zh[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
