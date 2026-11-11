#include <bits/stdc++.h>

using namespace std;
long long a[500005],b[300005],c[300005],d[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,x=0,q=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(x<n){
        for(int i=x;i<n;i++){
            if(c[a[i]]!=0){
                memset(c,300005,0);
                memset(d,500005,0);
                q=0;
            }
            c[a[i]]++;
            d[q]=a[i];
            q++;
        }
        x++;
        for(int i=0;i<q;i++){
            b[d[i]]++;
        }
        memset(c,300005,0);
        memset(d,500005,0);
        q=0;
    }

    for(int i=0;i<m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
