#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,li1,li2;
bool flag=false,f1=false,f2=false;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    li1+=s1[0];
    li1+=s1[1];
    li2+=s2[0];
    li2+=s2[1];
    if(li1==li2){
        flag=true;
        cout<<1;
    }else{
        cout<<0;
    }
    char side1=s1[2],side2=s2[2];
    if(side1=='A' or side1=='B' or side1=='C'){
        f1=true;
    }
    if(side2=='A' or side2=='B' or side2=='C'){
        f2=true;
    }
    if(flag==true and f1==f2 ){
        cout<<1;
    }else{
        cout<<0;
    }

    if(flag==true and side1=='A' and side2=='B'){
        cout<<1;
    }else if(flag==true and side1=='B' and (side2=='A' or side2=='C') ){
        cout<<1;
    }else if(flag==true and side1=='C' and side2=='B'){
        cout<<1;
    }else if(flag==true and (side1=='D' and side2=='F') or (side1=='F' and side2=='D') ){
        cout<<1;
    }else{
        cout<<0;
    }


    return 0;
}
