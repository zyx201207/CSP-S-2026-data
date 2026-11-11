#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int lin1=(s1[0]-'0')*10+s1[1]-'0';
    int lin2=(s2[0]-'0')*10+s2[1]-'0';
    char sea1=s1[2];
    char sea2=s2[2];
    if (c1==c2 && c1!=1 &&c1!=16 && c2!=1 && c2!=16){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if (lin1==lin2 && c1==c2 && c1!=1 &&c1!=16 && c2!=1 && c2!=16){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if (lin1==lin2 && c1==c2 && c1!=1 &&c1!=16 && c2!=1 && c2!=16){
        if (sea1>='A'&&sea1<='C' && sea2>='A'&&sea2<='C' &&sea1!=sea2 || sea1>='D'&&sea1<='E' && sea2>='D'&&sea2<='E' &&sea1!=sea2){
            cout<<"1";
        }
        else cout<<"0";
    }
    else{
        cout<<"0";
    }
    if (lin1==lin2 && c1==c2 && c1!=1 &&c1!=16 && c2!=1 && c2!=16){
        if (sea1>='A'&&sea1<='C' && sea2>='A'&&sea2<='C' &&sea1!=sea2 || sea1>='D'&&sea1<='E' && sea2>='D'&&sea2<='E' &&sea1!=sea2){
            if (sea1+1==sea2 || sea2+1==sea1){
                cout<<"1";
            }
            else cout<<"0";
        }
        else cout<<"0";
    }
    else{
        cout<<"0";
    }
    return 0;

}
