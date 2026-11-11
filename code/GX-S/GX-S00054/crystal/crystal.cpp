#include<bits/stdc++.h>
using namespace std;

long long n,m,cnt=0;
long long a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        long long ans=0;
        for(int j=i-1;j>=1;j--){
            int e=m;
            if(a[j]==a[i]) ans++;
            else if(a[j]!=a[i] && a[i]-a[j]<e){
                e=e-(a[i]-a[j]);
                ans++;

            }
        }
        cnt=max(ans,cnt);
    }
    cout << cnt+1 << endl;
    return 0;
}
