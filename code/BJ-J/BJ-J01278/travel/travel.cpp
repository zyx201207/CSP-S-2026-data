#include <bits/stdc++.h>
using namespace std;
bool ok(char c1,char c2){
    if(c1>c2)swap(c1,c2);
    if(c1<='C'&&c2>='D')return 1;
    else return 0;
}
bool near(char c1,char c2){
    if(c1>c2)swap(c1,c2);
    if(c1=='D'&&c2=='F')return 1;
    if(c1=='A'&&c2=='B')return 1;
    if(c1=='B'&&c2=='C')return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1;
    int a,b;
    cin>>a>>a1>>b>>b1;
    if(a!=b){
        cout<<"0000";
    }else{
        if(a1[0]!=b1[0]||a1[1]!=b1[1]){
            cout<<"1000";
        }else{
            if(ok(a1[2],b1[2])){
                cout<<"1100";
            }else{
                if(near(a1[2],b1[2])){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }
        }
    }
    return 0;
}