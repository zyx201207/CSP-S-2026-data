#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],now[500005],fn,tong[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int gamei=1;gamei<=n;gamei++){
        for(int i=1;i<=n+1;i++){
            now[i]=0;
        }
        fn=0;
        for(int paii=gamei;paii<=n;paii++){
            int pai=a[paii];
            bool havepai=false;
            int havepaii;
            for(int i=1;i<=fn;i++){
                if(now[i]==pai){
                    havepai=1;
                    havepaii=i;
                    break;
                }
            }
            if(havepai){
                for(int i=havepaii;i<=fn;i++){
                    now[i]=0;
                }
                fn=havepaii;
                now[fn]=a[paii];
            }
            else{
                fn++;
                now[fn]=a[paii];
            }
        }
        for(int j=1;j<=m;j++)
        for(int i=1;i<=fn;i++){
            if(now[i]==j){
                tong[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<" ";
    }
    return 0;
}
