#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    int s[a+1];
    string z;
    for(int i=0;i<=a;i++){
        char l;
        cin>>l;
        if(l>='a'&&l<='z'){
            z[i]=l;
        }
        else{
            s[i]=l;
        }
    }
    string q;
    for(int i=0;i<=a;i++){
        int zd=a;
    while(zd!=0){
        for(int p=0;p<=s[i];p++){
            q[i]+=z[i];
            }
        }
        zd--;
    }
    int zmjjkk=0;
    for(int i=0;i<=a;i++){
        for(int p=i;p<=i;p++){
            if(z[i]!=q[p]){
            zmjjkk++;
        }
        }
    }
    cout<<zmjjkk;
}
