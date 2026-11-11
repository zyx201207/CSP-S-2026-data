#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500009],b[300009],d[500009],cnt=0,p;
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt=0;
        p=0;
        for(int j=i;j<=n;j++){
            p=0;
            for(int k=1;k<=cnt;k++){
                if(d[k]==a[j]){
                    p=k;
                    break;
                }
            }
            if(p==0){
                cnt++;
                d[cnt]=a[j];
            }
            else{
                for(int k=p+1;k<=cnt;k++)  d[k]=0;
                cnt=p;
            }
        }
        for(int i=1;i<=cnt;i++){
            //cout<<d[i]<<" ";
            b[d[i]]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)  cout<<b[i]<<" ";
    return 0;
}//wok lwoer_bound忘了咋转下标了T-T
//宇宙的尽头是JJJ
//宇宙的尽头是JJJ
//宇宙的尽头是JJJ