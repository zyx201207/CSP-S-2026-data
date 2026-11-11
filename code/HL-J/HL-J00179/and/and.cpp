#include<bits/stdc++.h>
using namespace std;
int a,targ,ans,p[200010],ttg;
int box[20][200010];
int bidx[20];
int bas[20]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,200010};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>targ;ttg=targ;
    for(int i=1;i<=a;i++){
        scanf("%lld",&p[i]);
        for(int j=0;j<=18;j++){
            if(p[i]>=bas[j]&&p[i]<bas[j+1]){
                bidx[j]++;
                box[j][bidx[j]]=p[i];
                break;
            }
        }
    }
    for(int i=18;i>0;i--){
        if(ttg>bidx[i]){
            int bbb=bidx[i];
            for(int j=1;j<=bbb;j++){
                for(int k=0;k<=18;k++){
                    if(box[i][j]-bas[i]>=bas[k]&&box[i][j]-bas[i]<bas[k+1]){
                        bidx[k]++;
                        box[k][bidx[k]]=box[i][j]-bas[i];
                        bidx[i]--;
                        break;
                    }
                }
            }
        }
    }
    for(int i=18;i>=0;i--){
        if(ttg<=bidx[i]){
            ans+=bas[i];
        }
        if(ttg>=bidx[i]){
            int bbb=bidx[i];
            for(int j=1;j<=bbb;j++){
                for(int k=0;k<=18;k++){
                    if(box[i][j]-bas[i]>=bas[k]&&box[i][j]-bas[i]<bas[k+1]){
                        bidx[k]++;
                        box[k][bidx[k]]=box[i][j]-bas[i];
                        bidx[i]--;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//Trick||Treat!
