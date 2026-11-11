#include<bits/stdc++.h>
using namespace std;
string train_R,row_R,train_X,row_X;
string p=" ",p1=" ";
int a,b;
int s,s1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>train_R>>row_R>>train_X>>row_X;
    if(train_R==train_X)cout<<1;
    else {cout<<"0000";return 0;}
    if(row_R[0]-'0'==0)s=row_R[1]-'0';
    else s=(row_R[0]-'0')*10+(row_R[1]-'0');
    if(row_X[0]-'0'==0)s1=row_X[1]-'0';
    else s1=(row_X[0]-'0')*10+(row_X[1]-'0');
    a=row_R[2]-'A'+1,b=row_X[2]-'A'+1;
    if(s==s1)cout<<1;
    else {cout<<"000";return 0;}
    if(a<=3&&b<=3||a>3&&b>3)cout<<1;
    else {cout<<"00";return 0;}
    if(abs(a-b)==1&&a!=3&&b!=4)cout<<1;
    else cout<<0;
    return 0;
}
