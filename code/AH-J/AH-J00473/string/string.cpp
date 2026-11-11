#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+10;
int a[maxn];
string c[maxn];
string sum;
int sum2=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];j++){
           sum+=c[i];
        }
        sum2+=a[i];
    }
    int ans=0;
    for(int i=1;i<=sum2/2;i++){
        if(sum[i]!=sum[sum2-i+1]){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
