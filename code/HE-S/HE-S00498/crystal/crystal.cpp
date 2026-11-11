#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[99999],b=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]*i>a[n]){
            for(int j=1;j<=m;j++){
                if(a[j]==a[i]){
                    b++;
                }
                else{
                    m-=a[i]-a[j];
                    a[j]+=a[i]-a[j];
                    b++;
                }
            }
            break;
        }
    }
    b++;
    cout<<b;
    return 0;
}
