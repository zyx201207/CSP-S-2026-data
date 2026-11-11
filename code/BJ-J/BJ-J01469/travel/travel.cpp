#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int l1=0,l2=0,l3=0,l4=0;
    if(a==c){
     l1=1;
    }
    if((l1==1) && (b[0]==d[0]) && (b[1]==d[1])){
    l2=1;
    }
    int s1=0,s2=0;
    if(b[2]>='D'){
          s1=1;
    }
    if(d[2]>='D'){
          s2=1;
    }
    if((l2==1) && (s1==s2) ){
           l3=1;
    }
    if((l3==1) && ((abs(b[2]-d[2])==1) || (s1=1))){
          l4=1;
    }
    cout<<l1<<l2<<l3<<l4;
return 0;
}
