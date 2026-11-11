#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k,ans,x=1,y=0,b[N];
char a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long m;
        char c;
        cin>>m>>c;
        a[i]=c;
        b[i]=m;
        k+=m;
    }
    k/=2;
    while(k>0){
        if(x+y==n){
            cout<<ans;
            return 0;
        }
        if(a[x]!=a[n-y]){
            if(b[x]>b[n-y]){
                b[x]-=b[n-y];
                k-=b[n-y];
                ans+=b[n-y];
                b[n-y]=0;
                y++;
            }
            else if(b[x]==b[n-y]){
                b[x]-=b[n-y];
                k-=b[n-y];
                ans+=b[n-y];
                b[n-y]=0;
                y++;
                x++;
            }
            else{
                b[n-y]-=b[x];
                k-=b[x];
                ans+=b[x];
                b[x]=0;
                x++;
            }
        }
        else{
            if(b[x]>b[n-y]){
                b[x]-=b[n-y];
                k-=b[n-y];
                b[n-y]=0;
                y++;
            }
            else if(b[x]==b[n-y]){
                b[x]-=b[n-y];
                k-=b[n-y];
                b[n-y]=0;
                y++;
                x++;
            }
            else{
                b[n-y]-=b[x];
                k-=b[x];
                b[x]=0;
                x++;
            }
        }
    }
    cout<<ans;
    return 0;
}

