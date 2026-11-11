#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }else{
        long long maxx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }

    return 0;
}