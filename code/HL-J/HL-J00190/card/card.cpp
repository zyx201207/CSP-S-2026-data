#include <bits/stdc++.h>
using namespace std;
int n,m;
int v=0;
int a[500005];
bool u[300005];
int t[300005];
int o[500005];
void psh(int b){
    for(int i=v;i>=0;i--){
        if(a[i]==b){
            for(int j=i;j<n;j++){
                a[j]=0;
            }
            break;
        }else{
            u[a[i]]=0;
        }
    }

}
bool yn(int b){
    bool s=0;
    for(int i=v;i>=0;i--){
        if(a[i]==b){
            s=1;
            break;
        }
    }
    return s;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>o[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=i;j<n;j++){
            if(yn(o[j])){
               psh(o[j]);
            }else{
                a[v]=o[j];
                u[o[j]]=1;
                v++;
            }
        }

        for(int j=0;j<50003;j++){
            if(u[j]){
               t[j]++;
            }
        }


    }
    for(int i=0;i<=n;i++){
        if(t[i]!=0){
            cout<<t[i]<<' ';
        }
    }



    return 0;

}
