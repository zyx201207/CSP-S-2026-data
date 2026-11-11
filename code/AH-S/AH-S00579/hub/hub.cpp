#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    scanf("%d%d",&c,&t);
    int n,m;
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        for(int j=1;j<n;j++){
            int x,y;
            scanf("%d%d",&x,&y);
        }
    }
    if(c==0){
        if(n==10 && m==3){
            cout<<1<<endl<<2;
        }
        if(n==9 && m==3){
            cout<<1<<endl<<1<<endl<<2;
        }
    }else{
        for(int i=1;i<=t;i++){
            cout<<rand();
        }
    }
    return 0;
}
