#include<bits/stdc++.h>
using namespace std;
int bb;
int aaaa=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=1;
    string b;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a1;
        char a2;
        cin>>a1>>a2;
        for(int i=1;i<=a1;i++){
            b[c]=a2;
            c++;
        }
    }
    for(int i=1;i<=c/2;i++){
        if(b[i]!=b[n-i+1]){
            aaaa++;
        }
    }
    cout<<aaaa;
    return 0;
}