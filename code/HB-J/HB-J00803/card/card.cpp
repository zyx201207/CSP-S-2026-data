#include<bits/stdc++.h>
using namespace std;

int a[500010];


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    bool ta=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]<a[i-1]){
            ta=0;
        }
    }
    if(m==1){
        cout<<n;
    }else if(m==2){//1-3 13-14
        int c[3]={};
        for(int i=1;i<=n;i++){
            c[a[i]]++;
            if(a[n]!=a[i]) c[a[n]]++;
        }
        cout<<c[1]<<" "<<c[2];
    }else if(ta){//7-9 20
        for(int i=1;i<=n;i++){
            while(a[i]==a[i+1]) i++;
            cout<<i<<" ";
        }
    }else if(n<=500){//4-6
        int cnt[210]={};
        for(int i=1;i<=n;i++){
            int b[510]={};
            int pos=1;
            for(int j=i;j<=n;j++){
                b[pos]=a[j];
                pos++;
                for(int k=pos-2;k>=1;k--){
                    if(b[pos-1]==b[k]){
                        pos=k+1;
                        break;
                    }
                }
            }
            for(int k=1;k<pos;k++){
                cnt[b[k]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
    }
    //12+8+12+4+12=48pts
    return 0;
}
