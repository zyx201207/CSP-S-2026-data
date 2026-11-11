#include<bits/stdc++.h>
using namespace std;
long long a[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(m==1){
        long long x,maxx=0;
        for(int i=1;i<=n;i++){
            cin>>x;
            maxx=max(maxx,x);
        }
        cout<<maxx;
    }else if(m==n){
        long long x,maxx;
        cin>>x;
        maxx=x;
        for(int i=2;i<=n;i++){
            cin>>x;
            maxx=maxx&x;
        }
        cout<<maxx;
    }else if(m==2){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                long long t=a[i]&a[j];
                maxx=max(maxx,t);
            }
        }
        cout<<maxx;
    }
    return 0;
}
