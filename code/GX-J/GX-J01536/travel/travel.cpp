#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,c,d;
int m,n;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char x,y;
    x=("A"||"B"||"C"||"D"||"F");
    y=("A"||"B"||"C"||"D"||"F");

    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    s1=m+x;
    s2=n+y;

    if((c1==01)||(c1==16)||(c2==01)||(c2==16)){
        a=0;
}
    else a=1;
    if(c1==c2){
        b=1;
    }
    else b=0;
    if(m==n){
        c=1;
    }
    else c=0;
    if(( x=("A"||"B"))&&(y=("A"||"B"))||((x=("C"||"D"||"F"))&&(y=("C"||"D"||"F")))&&(x!=y))
    d=1;
    else d=0;




    cout<<a<<b<<c<<d<<endl;



    return 0;
}
