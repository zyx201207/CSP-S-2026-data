#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum,ans,p;
char s[N];
string t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        sum+=a[i];
        for(int j=1;j<=a[i];j++){
            p++;
            t[p]=s[i];
        }
    }
        for(int i=1;i<=sum/2;i++){
            if(t[i]!=t[sum-i+1]){
                ans++;
            }
        }
    cout<<ans;
    return 0;
}
