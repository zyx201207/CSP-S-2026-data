#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n;
long long len[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    long long x=1,y=n,ans=0;
    long long lenx=len[1],leny=len[n];
    for(;;){
        if(lenx>leny){
            if(c[x]!=c[y]) ans+=leny;
            lenx-=leny;
            y--;
            leny=len[y];
        }
        else{
            if(lenx==leny){
                if(c[x]!=c[y]) ans+=leny;
                x++;
                lenx=len[x];
                y--;
                leny=len[y];
            }
            else{
                if(c[x]!=c[y]) ans+=lenx;
                leny-=lenx;
                x++;
                lenx=len[x];
            }
        }
        if(y==0||x>n) break;
    }
    printf("%lld",ans/2);
    return 0;
}
