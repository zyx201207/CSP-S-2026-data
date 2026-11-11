#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    string pan[100000005];
    string jun[100000005];
    int a,sum=0,w=0,fan=0,b;
    char c;
    cin>>a;
    for(int i=1;i<=a;i++){
       
        cin>>b>>c;
        sum+=b;
        for(int j=1;j<=b;j++){
            pan[j]=c;
        }
    }
    for(int q=sum,q>=1;q--){
        w=sum-p+1;
        jun[q]=pan[w];
    }
    for(int e=sum,e>=1;e--){
        if(pan==jun){
            cout<<fan;
            break;
        }
        fan++;
        w=sum-e+1;
        pan[e]=jun[w];
    }
    return 0;
}
