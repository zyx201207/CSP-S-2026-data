#include<bits/stdc++.h>
using namespace std;
int w[500006];
int xlt[502][500006];
int sjb[502][500006];
/*struct yzy{
    int ks;
    int js;
    int sj;
    bool star=0;
    int xh;
};
yzy num[10000000];*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,jsq=1,nb=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>xlt[i][0];
        nb+=xlt[i][0]-1;
        cin>>xlt[i][1]>>sjb[i][1];
        //num[jsq].ks=xlt[i][1];
        //num[jsq].sj=sjb[i][1];
        //num[jsq].xh=jsq;
        jsq++;
        for(int j=2;j<=xlt[i][0];j++){
            cin>>xlt[i][j]>>sjb[i][j];
           // num[jsq].ks=xlt[i][j];
            //num[jsq].xh=jsq;
            //num[jsq-1].js=xlt[i][j];
            //num[jsq-1].sj+=sjb[i][j];
           // num[jsq].sj=sjb[i][1];
            jsq++;
        }
        jsq--;
    }
    for(int i=1;i<=q;i++){
        int s,e,jjj=0,jjjm=10000,jj;
        bool ks=0,js=0;
        jsq=0;
        cin>>s>>e;
        jsq+=w[s]+w[e];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=xlt[i][0];j++){
                if(xlt[i][j]==s){
                    ks=1;
                }
                if(xlt[i][j]==e){
                    js=1;
                }
                if(ks==1||js==1){
                    jjj+=sjb[i][j];
                }
                if(ks==1&&js==1){
                    jjjm=min(jjj,jjjm);
                    ks=0;
                    js=0;
                    jjj=0;
                }
            }
        }


        /*jjj=100000;
        for(int j=1;j<=nb;j++){
            if(num[j].ks==s&&num[j].js==s&&num[j].ks==e&&num[j].js==e){
                num[j].star=1;
            }
        }
        for(int j=1;j<=nb;j++){
            if(num[j].star==1){
                for(int k=1;k<=nb;k++){
                    if(num[k].star==1&&num[k].xh!=num[j].xh&&(num[k].ks==num[j].ks||num[k].ks==num[j].js||num[k].js==num[j].ks||num[k].js==num[j].js)){
                        jj=num[k].sj+num[j].sj;
                        jjj=min(jj,jjj);
                    }
                }
            }
        }
        if(jjjm==0){
            cout<<jsq+jjj<<"\n";
        }
        else{
            cout<<min(jjj,jjjm)+jsq<<"\n";

        }*/
        cout<<jsq+jjjm<<"\n";
    }


    return 0;
}
