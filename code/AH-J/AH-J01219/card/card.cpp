#include<bits/stdc++.h>
using namespace std;
int b[600000],c[400000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    int t;
    for(int i=1;i<=n;i++){
        int a[600000]={0};
        for(int j=i;j<=n;j++){
            bool w=true;
            for(int k=1;k<=j;k++){
                if(b[j]==a[k]){
                        t=k;
                        w=false;
                }
            }
            if(w==false){
                for(int p=t;p<=j;p++){
                    a[p]=0;
                }
                a[t]=b[j];
            }else{
                a[j]=b[j];
            }
        }
        for(int y=1;y<=n;y++){
            if(a[y]!=0){
                c[a[y]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=0){
            cout<<c[i]<<' ';
        }
    }
    return 0;
}
