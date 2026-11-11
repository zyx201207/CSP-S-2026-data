#include<bits/stdc++.h>
using namespace std;
int n,x;
int z=0;
int num=0;
char y;
char s[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        for(int j=0;j<x;j++){
            s[j]='y';
            z++;
        }
    for(int k=0;k<z;k++){
        if(s[k]!=s[z-k]){
            num++;
        }
        if(k==z-k){
            break;
        }
    }
    cout<<num;
    return 0;
    }
}
