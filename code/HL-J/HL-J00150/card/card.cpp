#include<bits/stdc++.h>
using namespace std;
int const MAXN=1e6+5;
int now[MAXN];
int num[MAXN];
int tong[MAXN];
int tong_2[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>num[n];
    }
    int cnt=1;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            tong[num[j]]++;
            for(int k=1;k<=n;k++){
                if(tong[k]==2){
                    memset(tong,0,sizeof(tong));
                    memset(now,0,sizeof(now));
                    cnt=1;
                    }
                tong[num[j]]++;
                now[cnt]=num[j];
            }
            cnt++;
        }
         for(int aaa=1;aaa<=n;aaa++){
            tong_2[num[aaa]]++;
        }
        memset(now,0,sizeof(now));
    }
    for(int i=1;i<=n;i++){
        cout<<tong_2[i]<<" ";

    }

    return 0;
}
