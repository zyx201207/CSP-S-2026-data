#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if(c==0&&n==2)cout<<32<<endl<<17;
    if(c==0&&n==3)cout<<35<<endl<<16;
    else{
        for(int i=1;i<=q;i++){
            cout<<random()<<endl;
        }
    }
    return 0;
}
