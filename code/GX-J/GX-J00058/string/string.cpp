#include<bits/stdc++.h>
using namespace std;


int nb ,ggb,piao=0;
char cnmb;
string fk,bch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>nb;
    for(int i=1;i<=nb;i++){
        cin>>ggb>>cnmb;
        for(int j=1;j<=ggb;j++)fk+=cnmb;
    }

    for(int i=fk.size();i>=1;i--){
        bch+=fk[i];

    }
    for(int i=0;i<fk.size();i++){
        if(fk[i]!=bch[i])piao++;
    }
    cout<<piao;











    return 0;}
