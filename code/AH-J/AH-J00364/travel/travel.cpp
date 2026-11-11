#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
bool f(string w,string w1){
     if(w=="D"&&w1=="F"||w=="F"&&w1=="D"){
         return 1;
     }if(w=="A"&&w1=="B"||w=="B"&&w1=="A"||w=="A"&&w1=="C"||w=="C"&&w1=="A"||w=="B"&&w1=="C"||w=="C"&&w1=="B"){
         return 1;
     }
     return 0;
}bool f1(string w,string w1){
     if(w=="D"&&w1=="F"||w=="F"&&w1=="D"){
         return 1;
     }if(w=="A"&&w1=="B"||w=="B"&&w1=="A"||w=="B"&&w1=="C"||w=="C"&&w1=="B"){
         return 1;
     }
     return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string t=s1.substr(0,2);
        string t1=s2.substr(0,2);
        if(t==t1){
            cout<<1;
            string w=s1.substr(2,1);
            string w1=s2.substr(2,1);
            if(f(w,w1)){
                cout<<1;
                if(f1(w,w1)){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }fclose(stdin);
    fclose(stdout);
    return 0;
}
