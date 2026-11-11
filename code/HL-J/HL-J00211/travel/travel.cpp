#include<bits/stdc++.h>
using namespace std;
string a,a_h,b,b_h;
int pd[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a_h>>b>>b_h;
    if(a==b){
        pd[0]=1;
    }else{
        pd[0]=0;
    }
    char l=a_h[0],l2=a_h[1],h=b_h[0],h2=b_h[1];
    if(pd[0]==0){
        pd[1]=0;
    }else if(l==h && l2==h2){
        pd[1]=1;
    }else{
        pd[1]=0;
    }
    if(pd[1]==0){
        pd[2]==0;
    }else if((a_h[2]<='C' && b_h[2]<='C') || (a_h[2]>'C' && b_h[2]>'C')){
        pd[2]=1;
    }else{
        pd[2]=0;
    }
    int aa=(int(l)-'0')*10+int(l2)-'0';
    int bb=(int(h)-'0')*10+int(h2)-'0';
    if(pd[2]==0){
        pd[3]=0;
    }else if(aa==bb && (a_h[2]-b_h[2]==1 || b_h[2]-a_h[2]==1)){
        pd[3]=1;
    }else{
        pd[3]=0;
    }
    for(int i=0;i<4;i++){
        cout<<pd[i];
    }
    return 0;
}
