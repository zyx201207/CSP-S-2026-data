#include<bits/stdc++.h>
using namespace std;
string q,w,e,r;
bool f1,f2,f3,f4;
bool check1(char c1,char c2){
    if(c1=='A'||c1=='B'||c1=='C'){
        if(c2=='A'||c2=='B'||c2=='C'){
            return 1;
        }
    }else{
        if(c2=='D'||c2=='F'){
            return 1;
        }
    }return 0;
}bool check2(char c1,char c2){
    if(c1=='A'){
        if(c2=='B'){
            return 1;
        }
    }if(c1=='B'){
        if(c2=='A'||c2=='C'){
            return 1;
        }
    }if(c1=='C'){
        if(c2=='B'){
            return 1;
        }
    }if(c1=='D'){
        if(c2=='F'){
            return 1;
        }
    }if(c1=='F'){
        if(c2=='D'){
            return 1;
        }
    }return 0;
}int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>q>>w>>e>>r;
    if(q==e){
        f1=1;
        if(w[0]+w[1]==r[0]+r[1]){
            f2=1;
            if(check1(w[2],r[2])){
                f3=1;
                if(check2(w[2],r[2])){
                    f4=1;
                }
            }
        }
    }cout<<f1<<f2<<f3<<f4;
    return 0;
}
