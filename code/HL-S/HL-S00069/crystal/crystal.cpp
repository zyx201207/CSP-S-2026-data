#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500010],cnt=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cnt+=(i-1)*(a[i]-a[i-1]);
        if(cnt>m){
            cout<<i-1;
            break;
        }
    }
}
