#include<bits/stdc++.h>
using namespace std;
int n,k[1000005],g=0,l=0,b=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        char a;
        cin>>m>>a;
        g+=m;
        for(int j=i;j<=m+i-1;j++){
            k[j+i]=int(a);
        }
    }
    for(int i=1;i<=g+1;++i){
        if(k[i+1]!=k[i+2])l++;
    }
    if(l==0){
        cout<<0;
        return 0;
    }
    if(l>0){
        for(int i=1;i<=g+1;++i){
            if(k[2]!=k[g+1]){
                if((g+1)%2==0){
                    cout<<(g-3)/2;
                    return 0;
                }
                else{
                    cout<<g/2;
                    return 0;
                }
            }
            if(k[2]==k[g+1]){
                if(g>3){
                    cout<<1;
                    return 0;
                }
                if(g==3){
                    cout<<0;
                    return 0;
                }
            }
        }

    }
}
