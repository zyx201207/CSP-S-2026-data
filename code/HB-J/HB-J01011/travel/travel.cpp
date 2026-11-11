#include<bits/stdc++.h>
using namespace std;
int x[3];
int abs(int x){
    if(x<0)
        return -x;
    else
        return x;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    int t=0;
    if(a==b){
        x[0]=1,x[1]=1;
        while(t<=1){
         if(c[t]!=d[t]){
            x[1]=0;
            t=2;
          }
          t++;
     }
    }
    else{
        x[1]=0,x[0]=0;
    }
    if(c[3]=='A'||c[3]=='B'||c[3]=='C'){
        if(abs((c[3]-'0')-(d[3]-'0'))==1){
            x[2]=1;
            if(abs((c[3]-'0')-(d[3]-'0'))==1)
                x[3]=1;
            else
                x[3]=0;
        }
        else
            x[2]=0;
    }else{
        if(abs((c[3]-'0')-(d[3]-'0'))==2){
            x[2]=1;
            if(abs((c[3]-'0')-(d[3]-'0'))==2)
                x[3]=1;
            else
                x[3]=0;
        }
        else
          x[2]=0;  
    }
    cout<<x[0]<<x[1]<<x[2]<<x[3];
    fclose(stdin);
    fclose(stdout);
    return 0;
}