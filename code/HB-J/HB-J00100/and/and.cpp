#include<bits/stdc++.h>
using namespace std;
long long abc(long long a){
    long long x=0,i=1,b=0,y=0,w=0;
    while(true){
        if(a-i<0){
            b=i/2;
            break;
        }
        i=i*2;
    }
    i=1;
    while(true){
        if(a-b>=0){
            a = a-b;
            x=x*10+1;
            w++;
        }
        else{
            x=x*10;
            w++;
        }
        if(b==1){
            if(a==1){
                x=x*10+1;
                w++;
                break;
            }
            else{
                x=x*10;
                w++;
                break;
            }
        }
        else b=b/2;
    }
    for(int i=1;i<=w;i++){
        y += y*10+x%10;
        x=floor(x/10);
    }
    return y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,s=0,e=0;
    cin>>a>>b;
    long long z[a+10]={0},aaa[a+10]={0};
    for(int i=1;i<=a;i++){
        cin>>z[i];
        aaa[i] = abc(z[i]);
    }
    s=aaa[i]
    for(int i=1;i<=a;i++){
        if(aaa[i]>s){
            s = aaa[i];
            e=i;
        }
    }
    cout<<e;
    return 0;
}
