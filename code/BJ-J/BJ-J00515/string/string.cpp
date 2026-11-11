#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    double e=0;
    for(int i=0;i<n;i++){
        e+=a[i];
    }
    e=e/2;
    int u=0;
    int o=0,p=n-1;

    for(int i=0;u<=e;i++){
        u+=a[i];
        o=i;
    }
    for(int i=n-1;i>o;i--){
        swap(a[i],a[i+1]);
        swap(b[i],b[i+1]);

    }
    p=0;
    for(int i=0;i<o;i++){
        p+=a[i];
    }
    a[o+1]=a[o]-e+p;
    a[o]=e-p;

    b[o+1]=b[o];
    p=n;
    u=0;

    int y=0;
    while(u<p){
        if(a[u]>=a[p]){

            if(b[u]!=b[p]){
                y+=a[p];
            }
            if(a[u]==a[p]){
                u++;
                p--;
                continue;
            }
            a[u]-=a[p];
            p--;
            continue;
        }else{
            if(b[u]!=b[p]){
                y+=a[u];
            }
            a[p]-=a[u];
            u++;
            continue;
        }

    }
    cout<<y;
}
