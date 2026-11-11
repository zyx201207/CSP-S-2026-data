#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string y,ry;
    for(int i=1;i<=n;i++){
        int j;
        char o;
        cin>>j>>o;
        if(j>=100000){
        for(int p=1;p<=j/4+j%4;p++){
            y+=o;
        }
        string t=y;
        y+=t;
        y+=t;
        y+=t;
        y+=t;
        }else{
        for(int p=1;p<=j;p++){
            y+=o;
        }
        }

    }
    //cout<<y;


    int cnt=0,f=1;
        int len=y.size();
        int w=len/2;
        if(len%2==0){
            f=0;
        }


    for(int i=1;i<=w;i++){
        if(y[w+f]!=y[i]){
           cnt++;
       }
        f++;


   }
   //cout<<y<<endl<<ry<<endl;
    cout<<cnt;
    return 0;

}

