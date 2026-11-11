#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,t=0,k=0;
    char c[1000],s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>s;
        for(int j=a;j>0;j--){
            c[t]=s;
            t+=1;
        }
    }
    t-=1;
    for(int i=0;i<=t/2;i++){
        if(c[i]!=c[t-i])
            k+=1;
    }
    cout<<k;
    return 0;
}
