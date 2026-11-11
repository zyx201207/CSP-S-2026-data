#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
long long n,a[N];
char c[N];
long long cnt,len;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    long long l=1,r=len,x=0,y=n+1,op=0;
    while(l<r){
        if(op==0){
            x++;
            y--;
        }
        else if(op==-1){
            y--;
        }
        else {
            x++;
        }
        if(x==y){
            break;
        }
        if(a[x]>a[y]){
            r-=a[y];
            l+=a[y];
            a[x]-=a[y];
            if(c[x]!=c[y]) cnt+=a[y];
            op=-1;
        }
        else if(a[x]<a[y]){
            l+=a[x];
            r-=a[x];
            a[y]-=a[x];
            if(c[x]!=c[y]) cnt+=a[x];
            op=1;
        }
        else{
            l+=a[x];
            r-=a[y];
            if(c[x]!=c[y]) cnt+=a[x];
            op=0;
        }

    }
    cout<<cnt;
    return 0;
}
