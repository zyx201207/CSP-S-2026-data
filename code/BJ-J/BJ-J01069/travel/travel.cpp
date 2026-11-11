#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string s1,s2;
    cin >> n >> s1 >> m >> s2;
    bool f=1;
    if(n==m){
        cout << 1;
    }else{
        cout << 0;
        f=0;
    }
    int p1=s1[0]*10+s1[1];
    int p2=s2[0]*10+s2[1];
    if(p1==p2 && f==1){
        cout << 1;
    }else{
        cout << 0;
        f=0;
    }
    if(s1[2]<='C' && s2[2]<='C' && f==1){
        cout << 1;
    }else if(s1[2]>='D' && s2[2]>='D' && f==1){
        cout << 1;
    }else{
        cout << 0;
        f=0;
    }
    if(f==1 && int(s1[2]-s2[2])==1){
        cout << 1;
    }else if(f==1 && int(s2[2]-s1[2])==1){
        cout << 1;
    }else if(f==1 && s1[2]=='D' && s2[2]=='F'){
        cout << 1;
    }else if(f==1 && s1[2]=='F' && s2[2]=='D'){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
