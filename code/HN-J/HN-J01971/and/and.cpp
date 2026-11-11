#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i];}
    int b[n];

    for(int i=0;i<n;i++){
        int x=0,y=1 ;
        while(c[i]>0){
            x+=c[i]%2*y;
            y*10;
            c[i]=c[i]/2;
        }
        b[i]=x;}
    int maxn=0,now=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int z=0;
            for£¨int l=0;l<m-1;l++£©{
                if(i!=j &&maxn<b[i]||b[j]){
                    now=b[i]||b[j];
                    maxn=now||b[j+z];
                    z++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        int aleph=0,zayin=1;
        while(maxn>0){
            aleph+=maxn%10*zayin;
            zayin=zayin*2;
            maxn/10;
        }
    }
    cout<<aleph;
    return 0;
    }

