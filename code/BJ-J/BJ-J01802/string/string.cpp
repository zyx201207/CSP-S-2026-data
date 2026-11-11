#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%d",&n);
    long long a[n+2];
    char b[n+2]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    string s="";
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            s+=b[i];
        }
    }
    for(int i=1;i<=(n+1)/2;i++){
        if(s[i]!=s[n-i+1]){
            return 0;
        }
    }
    printf("0");
    return 0;
}
