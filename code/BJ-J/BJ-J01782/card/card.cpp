#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ax{
    ll shu,we;
};
ll n,m,a[500005],am[300005],aq[300005],as[300005];//
ll ao[50005],da[100005];
bool poki;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            poki=true;
        }
        am[a[i]]++;
        aq[a[i]]=i;
        if(a[i]!=a[i-1]){
            as[a[i-1]]=i-1;
        }
    }
    as[a[n]]=n;
    if(!poki){
        for(int i=1;i<=m;i++){
            if(am[i]>0){
                int zqh=0;
                int qr=am[i]%2;
                zqh+=qr*(aq[i]-1);
                zqh+=(as[i]-aq[i])/2+1;
                cout<<zqh<<' ';
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            int wei=0;
            ax b[50005]={};
            for(int j=i;j<=n;j++){
                ao[++wei]=a[j];
                b[a[j]].shu++;
                if(b[a[j]].shu==2){
                    int po=b[a[j]].we;
                    for(int o=b[a[j]].we;o<=wei;o++){
                        b[a[o]].shu=0;
                        b[a[o]].we=0;
                        ao[o]=0;
                    }

                    wei=po;
                    ao[wei]=a[j];
                    b[a[j]].shu=1;
                }
                b[a[j]].we=wei;

            }
            for(int j=1;j<=wei;j++){
                da[ao[j]]++;
            }

        }
        for(int i=1;i<=m;i++){
            cout<<da[i]<<' ';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
