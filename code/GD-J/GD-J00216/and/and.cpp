#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[200010];
int ans=0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=30;i>=0;i--){
        sort(a+1,a+n+1,greater<int>());
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i)){
                cnt++;
            }
        }
        if(cnt>=m){
            n=cnt;
            ans+=1<<i;
        }
        for(int j=1;j<=n;j++){
            a[j]&=~(1<<i);
        }
    }
    cout<<ans;
    return 0;
}