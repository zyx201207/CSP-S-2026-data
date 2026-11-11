#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&d);
        int f=0,z=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<0){
                f++;
            }else{
                z++;
            }
        }
        if(f==4||z==4){
            cout<<1;
        }else if(f<4&&z<4){
            cout<<0;
        }else{
            int mx=max(f,z);
            cout<<mx/2;
        }
        cout<<endl;
    }


    return 0;
}
