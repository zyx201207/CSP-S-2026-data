#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long ls[200005];
    for(int i=1;i<=n;i++){
        cin>>ls[i];
    }
    if(m==1){
        long long a=0;
        for(int i=1;i<=n;i++){
            if(ls[i]>a) a=ls[i];
        }
        cout<<a;
    }
    else if(m==n){
        long long a=ls[1];
        for(int i=2;i<=n;i++){
            a&=ls[i];
        }
        cout<<a;
    }
    else{
        long long a=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=m;j++){
                a=max(a,ls[i]&ls[j]);
            }
        }
        cout<<a;
    }
    return 0;
}
