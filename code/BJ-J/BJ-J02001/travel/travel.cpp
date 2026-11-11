#include<bits/stdc++.h>
using namespace std;
struct _{
    int c,z;
    char cz;
    int s;
}a[3];
int j1(){
   if(a[1].c==a[2].c){
        return 1;
    }
    else{
        return 0;
    }
}
int j2(){
    if(a[1].z==a[2].z){
        return 1;
    }
    else{
        return 0;
    }
}
int j3(){
    if(a[1].s>=65&&a[1].s<=67){
        if(a[2].s>=65&&a[2].s<=67){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(a[2].s>=68&&a[2].s<=70){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int j4(){
    if(a[2].s>a[1].s){
        swap(a[2].s,a[1].s);
    }
    if((int)a[1].s<=67){
        if(a[1].s-a[2].s==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(a[1].s>67){
        if(a[1].s==70&&a[2].s==68){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a[1].c;
    cin>>a[1].z;
    cin>>a[1].cz;
    cin>>a[2].c;
    cin>>a[2].z;
    cin>>a[2].cz;
    a[1].s=(int)a[1].cz,a[2].s=(int)a[2].cz;
    int f1=j1();
    if(f1==1){
        cout<<1;
        int f2=j2();
        if(f2==1){
            cout<<1;
            int f3=j3();
            if(f3==1){
                cout<<1;
                int f4=j4();
                cout<<f4;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}