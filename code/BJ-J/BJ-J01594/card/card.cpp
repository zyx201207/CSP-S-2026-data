#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int ans[30005]={{0}};
    int n,m,dw=0;
    cin>>n>>m;
    int c[30005]={{0}},b[30005];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        bool jiyihua[30005]={{0}};
        dw=0;
        for(int g=i;g<=n;g++){
            if(jiyihua[c[g]]==0){
                ++dw;
                int qwryt=c[g];
                b[dw]=qwryt;
                jiyihua[g]=1;
            }else{
                for(int k=1;;k++){
                    if(b[k]==c[g]){
                        for(int kk=k+1;kk<=dw;kk++){
                            jiyihua[b[kk]]=0;
                            b[kk]=0;
                        }
                        dw-=dw-k;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=dw;i++){
            ans[b[i]]++;

        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";



    return 0;
}
