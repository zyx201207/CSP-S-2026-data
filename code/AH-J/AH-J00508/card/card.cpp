#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[300010],siz;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool f=0;
    int uu;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=siz;k++)
                if(a[j]==c[k]){
                    uu=k;
                    f=1;
                    break;
                }
            if(f==0){
                siz++;
                c[siz]=a[j];
            }else{
                int yy=siz;
                for(int l=uu;l<=yy;l++){
                    c[l]=0;
                    siz--;
                }
                siz++;
                c[siz]=a[j];
                f=0;
            }
        }
        for(int p=1;p<=siz;p++){
            b[c[p]]++;
        }
        siz=0;
        for(int j=1;j<=n;j++){
            c[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
