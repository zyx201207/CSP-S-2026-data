#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,k,a[2000005],y[2000005],c,cnt=0,t;
    long long d;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>y[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j-i>1){
                cnt+j-i;
            }
            if(y[i]-y[j]>d){
                i=j;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
