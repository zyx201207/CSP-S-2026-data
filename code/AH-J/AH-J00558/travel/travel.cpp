//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in", "r",stdin);
freopen("travel.out", "w",stdout);
string chexiang1,chexiang2,zuowei1,zuowei2;
cin>>chexiang1>>zuowei1>>chexiang2>>zuowei2;
int tyjcx=chexiang1==chexiang2;
cout<<tyjcx;
int tyjcxandtyp=tyjcx==1&&zuowei1[1]==zuowei2[1]&&zuowei1[0]==zuowei2[0];
cout<<tyjcxandtyp;
int tyjcxtyptyc=0;
if(tyjcxandtyp==1){
    if(zuowei1[2]=='A'){
        if(zuowei2[2]=='B'||zuowei2[2]=='C'){
            tyjcxtyptyc=1;
        }
    }
    if(zuowei1[2]=='B'){
        if(zuowei2[2]=='A'||zuowei2[2]=='C'){
            tyjcxtyptyc=1;
        }
    }
    if(zuowei1[2]=='C'){
        if(zuowei2[2]=='A'||zuowei2[2]=='B'){
            tyjcxtyptyc=1;
        }
    }
    if(zuowei1[2]=='D'){
        if(zuowei2[2]=='F'){
            tyjcxtyptyc=1;
        }
    }
    if(zuowei1[2]=='F'){
        if(zuowei2[2]=='D'){
            tyjcxtyptyc=1;
        }
    }
}
cout<<tyjcxtyptyc;
int xianglin=0;
if(tyjcxtyptyc==1){
    if(zuowei1[2]==zuowei2[2]+1){
        xianglin=1;
    }
    if(zuowei2[2]==zuowei1[2]+1){
        xianglin=1;
    }
}
cout<<xianglin;
    return 0;
}
