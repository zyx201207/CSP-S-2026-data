#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[200005],zf[200005],n,l,lfl,lfr,lbl,lbr,fcnt=1,bcnt=1,fnow,bnow,exch,le;
bool flag=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        getchar();
        zf[i]=getchar();
        l+=num[i];
    }
    while(flag==1){
        fnow=zf[fcnt];
        lfl=lfr;
        if(lfr+num[fcnt]>l/2){
            flag=0;
            lfr=l/2;
        }
        else
            lfr+=num[fcnt];
        while(lbr<lfr){
            bnow=zf[n-bcnt+1];
            lbl=lbr;
            if(le!=0){
                if(lbr+le>lfr){
                    le=le-num[fcnt];
                    lbr=lfr;
                }
                else{
                    lbr+=le;
                    le=0;
                    bcnt++;
                }
            }
            else{
                if(lbr+num[n-bcnt+1]>lfr){
                    le=lbr+num[n-bcnt+1]-lfr;
                    lbr=lfr;
                }
                else{
                    lbr+=num[n-bcnt+1];
                    bcnt++;
                }
            }
            if(bnow!=fnow)
                exch=exch+min(lfr,lbr)-max(lfl,lbl);
        }
        fcnt++;
    }
    cout<<exch<<endl;
    return 0;
}
