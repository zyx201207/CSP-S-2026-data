#include<bits/stdc++.h>
using namespace std;
int a[210000],c[210000],h[110000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        string s="";
        int len=0;
        for(int j=i;j<=n;j++){
            c[a[j]]++;
            if(c[a[j]]==2){
                c[a[j]]=1;
                int id;
                for(int k=0;k<=len;k++){
                    if((int)s[k]-48==a[k]){
                        id=k;
                        break;
                    }
                }
                len-=len-id;
            }else{
                s[len++]=a[j]+48;
            }
        }
        for(int j=0;j<=len;j++){
            h[j]+=c[j];
        }
    }
    for(int i=1;i<=m;i++) cout<<h[i]<<' ';
    return 0;
}
