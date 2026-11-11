#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int s[n]={};
    string a;
    char b;
    int tim=1;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>b;
        for(int j=1;j<=s[i];j++){
            a[tim]=b;
            tim++;
        }
    }
    int ans=0;
    int num=a.size();
    for(int i=1;i<=num/2;i++){
        if(a[i]!=a[tim]){
            ans++;
        }
        tim--;
    }
    return 0;
}
