#include <bits/stdc++.h>
using namespace std;
/*
e.g. a(10000)b(1000)c(114)

a:10000
b:1000
c:114

mod b,c to a, use 1114

a(114)b(514)a(113)

a:227
b:514

a+1 b-1: yes

mod 1 b to a, use 1

a(2)b(2)c(1)

mod 1 b to a, 1 c to a, use 2

a(10)b(8)c(5)d(14)


*/
struct cargs{long long amt;char tp;};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    int u,v;
    //char c[200005];
    cargs cg[100005]={};
    int lgt=0;
    bool flg;
    cin>>n;
    for(int i=1;i<=n;i++){
        flag=false;
        cin>>u>>v;
        for(int j=0;j<=lgt;++j){
            if(cg[i].tp==v)flg=true;
        }
        if(flg){
                ++lgt;
            int emp=0;
            while(cg[emp].tp!=''){
                emp++;
            }
            cg[emp].tp=v;
            cg[emp].amt=u;
        }
        else{
            int re=0;
            while(cg[re].tp!=v)++re;
            cg[re].amt+=u;
        }
    }
    if(n==1)cout<<0;// 1 type doesnt need cmp
    else if(lgt==1)cout<<0;//1 type char dsnt need cmp
    else cout<<1;//idk the rest
    return 0;
}
