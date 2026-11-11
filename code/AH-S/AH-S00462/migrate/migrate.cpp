#include<bits/stdc++.h>
using namespace std;
long long t,n,d,i,p,q,cnt,c;
long long a[3000010];
long long f[3000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        cin>>n>>d;
        cnt=0;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i+3<n;i++){
            if(a[i+3]-a[i]>d&&a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d){
                cnt++;
            }else if(a[i+3]-a[i+2]>d){
                i=i+3;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
