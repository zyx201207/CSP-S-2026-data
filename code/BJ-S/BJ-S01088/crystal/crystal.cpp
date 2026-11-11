#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],m;
int n;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);
    int ans=-1;
    for(int i=1;i<=n;i++){
        long long cnt=m;
        int c=0;
        int j=i+1;
        while(cnt>0&&j<=n){
            if(cnt-(a[i]-a[j])>=0){
                c++;
            }
            cnt-=(a[i]-a[j]);
            j++;
        }
        ans=max(c,ans);

    }
    cout<<ans+1<<"\n";
    return 0;
}
