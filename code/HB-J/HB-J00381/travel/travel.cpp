#include<bits/stdc++.h>
using namespace std;
int tra1,tra2,p1,p2;
string str1,str2;
bool check_side(char x,char y){
    int a,b;
    if(x=='A'||x=='B'||x=='C')a=1;
    else a=2;
    if(y=='A'||y=='B'||y=='C')b=1;
    else b=2;
    if(a==b)return true;
    else return false;
}
bool check_next(char x,char y){
    if(x>y)swap(x,y);
    return (x+1)==y?true:false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>tra1>>str1>>tra2>>str2;
    p1=(str1[0]-'0')*10+(str1[1]-'0');
    p2=(str2[0]-'0')*10+(str2[1]-'0');
    if(tra1==tra2){
        cout<<"1";
        if(p1==p2){
            cout<<"1";
            if(check_side(str1[2],str2[2])){
                cout<<"1";
                if(check_next(str1[2],str2[2])){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
