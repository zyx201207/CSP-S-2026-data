#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,m,c,t,mn,ans;
long long a[N];
void spfa(){
    long long d=m;
    for(int i=1;i<n;i++){
        long long r=i;
        for(int j=i+1;j<=n;j++){
            if((a[j]-a[r])<=d&&(a[j+1]-a[r])>d){
                mn++;
                r=j;
            }
        }
    }
    for(int i=n;i>1;i--){
        long long r=i;
        for(int j=n;j>=i-1;j--){
            if((a[j]-a[r])<=d&&(a[j+1]-a[r])>d){
                mn++;
                r=j;
            }
        }
    }
    if(mn==2){
        ans++;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=c;i++){
        cin>>n>>m;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i]);
        }
        spfa();
        cout<<ans<<endl;
    }
    return 0;
}


