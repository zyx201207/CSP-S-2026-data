#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, m, ans,a[N];
int main(){
    freopen("crystal.in","r",stdin);                                          
    freopen("crystal.out","w",stdout);                                        
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = n;i>=1;i--){
        long long l = m, s = 0;
        for(int j = i;j>=1;j--){
            if(l>=(a[i]-a[j])){
                l-=(a[i]-a[j]),s++;
            }
            else{
                break;
            }
        }
        ans = max(ans, s);
    }
    cout<<ans;
    return 0;
}
