#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long cnt=1;
    for(int i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
    }
    long long x=1,num=0;
    long long y=n+1-x;
    while(x<y){
        if(b[x]!=b[y]){
         num+=min(a[x],a[y]);
        }
        if(a[x]>a[y]){
            a[x]-=a[y];
            y--;
        }
        else if(a[x]==a[y]){
            x++;
            y--;
        }
        else{
            a[y]-=a[x];
            x++;
        }
    }
    cout<<num;
return 0;
}
