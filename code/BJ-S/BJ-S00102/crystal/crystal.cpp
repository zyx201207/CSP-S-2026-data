#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,ans;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f=1;
    cin>>a[1]>>a[2];
    int d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        cin>>a[i];
        if(a[i]-a[i-1]!=d) f=0;
    }
    if(f==1){
        int m2=m;
        for(int i=1;i<=1e9;i++){
            if(m2-d*i>=0){
                m2-=d*i;
                ans++;
            }
            else break;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int x=a[i],y=m,cnt=0;
        for(int j=i;j>=1;j--){
            if(x-a[j]<=y){
                y-=a[j];
                cnt++;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
