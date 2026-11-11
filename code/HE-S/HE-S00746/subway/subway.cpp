#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen(subway.in,"r",stdin);
    freopen(subway.out,"w",stdout);
    int c,n,m,d,q,w[100005],r,a[100005],t,s,e,tz;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cin>>r;
    for(int i=1;i<=2*r;i++){
        cin>>a[i]>>t;
        for(int i=1;i<=r/2-1;i+=2){
            if(a[i]==2){
                tz+=5+7+3+4;
            }
        }
    for(int i=1;i<=r-1;i++){
        cin>>s>>e;
    }
    }
    tz+=w[s]+w[e];
    return 0;
}

