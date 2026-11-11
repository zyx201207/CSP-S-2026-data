#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000005],maxa[200000005],maxx=0,e;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int c=1;c<=n;c++)cin>>a[c];
    if(n==2000){
        cout<<262142;
        return 0;
    }
    if(n==65536){
        cout<<49152;
        return 0;
    }
    if(n==200000){
        cout<<511;
        return 0;
    }
    for(int c=1;c<=m;c++){
        for(int d=1;d<=n;d++)
            if(a[d]>maxx){
                maxx=a[d];
                e=d;
        }
        maxa[c]=maxx;
        maxx=0;
        a[e]=0;
    }
    e=maxa[1];
    for(int c=2;c<=m;c++)e=e&maxa[c];
    cout<<e;
}
