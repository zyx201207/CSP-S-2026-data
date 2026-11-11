#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int a[MAXN],cnt[MAXN];
struct table{
    int num,posi;
}b[MAXM];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,maxa=-1;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>maxa) maxa=a[i];
    }
    for(int i=1;i<=n;i++){
        //初始化
        int pos=1;
        for(int j=1;j<=maxa;j++){
            b[j].num=0;
            b[j].posi=0;
        }

        for(int j=i;j<=n;j++){
            if(b[a[j]].num==0){
                b[a[j]].num=1;
                b[a[j]].posi=pos;
                pos++;
            } else{
                for(int k=b[a[j]].posi+1;k<pos;k++) b[a[k]].num=0; //清除
                pos=b[a[j]].posi+1;
            }
        }
        for(int j=1;j<=maxa;j++){
            if(b[j].num==1){
                cnt[j]++;
            }
            //cout << b[j].num << " ";
        }
        //cout << "\n";
    }
    for(int i=1;i<=maxa;i++) cout << cnt[i] << " ";
    return 0;
}
