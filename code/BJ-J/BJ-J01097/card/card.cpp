#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],s[300009],k=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])k=0;
        s[a[i]]=i;
    }
    if(k){
        for(int i=0;i<300009;i++){
        if(s[i])cout<<s[i]<<" ";
        }
    }
    if(m==2){
        int R=0,T=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]){
                if(a[i]==1)R++;
                else T++;
            }
            else R++,T++;
        }
    }
    return 0;
}
