#include<bits/stdc++.h>
using namespace std;
bool q[4]={0};
void pan(int a,int b){
    if(('A'<=a && a<='C') && ('A'<=b && b<='C')){
        q[2]=1;
        if(max(a,b)-min(a,b)==1)q[3]=1;
    }
    else if(('D'==a || a=='F') && ('D'<=b || b<='F')){
        q[2]=1;
        if(max(a,b)-min(a,b)==2)q[3]=1;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,w1,w2,wei1[3],wei2[3];

    cin >> x1 >> w1 >> x2>>w2;
    for(int i=0;i<1;i++){
        if(x1!=x2)break;
        else q[0]=1;
        if(w1[0]!=w2[0]||w1[1]!=w2[1])break;
        q[1]=1;
        char a=w1[2],b=w2[2]; 
        pan(a,b);
    }
    for(int i=0;i<4;i++){
        cout <<q[i];
    }
    return 0;
}