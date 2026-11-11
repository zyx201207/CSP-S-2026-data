#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int a,b;
    cin>>a>>b;
    int c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }

    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            if(c[i]<c[j]){
                int t=c[i];
                c[i]=c[j];
                c[j]=t;
            }
        }
    }
    int c1[b];
    for(int i=0;i<b;i++){
        int d=c[i];
        int e=0;
        int f=1;
        while(d){
            e=(d%2*f+e);
            f=f*10;
            d=d/2;
        }
        c1[i]=e;
    }
    int ans=c1[0];
    for(int i=1;i<b;i++){
        ans=ans&c1[i];
    }
    cout<<ans;
    return 0;
}
