#include<bits/stdc++.h>
using namespace std;
int a[200010],maxx,b[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int z=a[n];
    if(m==1) cout<<z;
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j==2) z=a[i]&a[j];
                else z=max(z,a[i]&a[j]);
            }
        }
        cout<<z;
    }
    else{
        for(int i=n;i>=1;i--){
            if(m<=1) break;
            z=z&a[i-1];
            m--;
        }
        cout<<z;
    }

    return 0;
}
