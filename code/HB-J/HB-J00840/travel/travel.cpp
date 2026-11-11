#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

char ch1,ch2;
bool flag=1,aaa=0,bbb=0,kkk=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
        flag=0;
    }
    if(flag&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<0;
        flag=0;
    }
    ch1=s1[2];
    ch2=s2[2];
    if(flag){
        if(ch1=='D'){
            if(ch2=='F'){
                cout<<1;
                kkk=1;
            }
        }
        else if(ch1=='F'){
            if(ch2=='D'){
                  cout<<1;
                  kkk=1;
            }
        }
        for(char i='A';i<='C';i++){
            if(ch2==i){
                aaa=1;
            }
            if(ch1==i){
                bbb=1;
            }
        }
        if(aaa==bbb==1){
            cout<<1;
            kkk=1;
            flag=0;
        }
        if(kkk==0){
            cout<<0;
            flag=0;
        }
    }
    else{
        cout<<0;
        flag=0;
    }
    if(flag&&(ch2==ch1-1||ch1==ch2-1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
