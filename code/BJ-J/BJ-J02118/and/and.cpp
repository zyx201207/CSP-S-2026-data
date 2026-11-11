#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long maxx=-1e15,sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum=a[1];
    if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(a[i],maxx);
        }
        cout<<maxx;
    }else{
        for(int i=2;i<=n;i++){
        sum&=a[i];
        }
        cout<<sum;
    }
    return 0;
}
