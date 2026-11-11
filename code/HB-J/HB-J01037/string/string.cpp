#include<bits/stdc++.h>
using namespace std;
int n,x,y=1,ans=0;
char a[1000000005],b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x>>b;
        for(int i=0;i<x;++i){
            a[y]=b;
            ++y;
        }
    }
    y--;
    for(int i=1;i*2<=y;++i){
        if(a[i]!=a[y-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
