#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[100005],ind[100005];
char c[100005];
long long l;
long long opp(long long a){
    return l-a-1;
}
//long long check(long long x){
//    int l = 1,r = n;
//    while(l<=r){
//        int mid = (l+r)/2;
 //       if(x<ind[mid]){
//            r = mid;
//        }
//        if(x==ind[mid]){
//            return mid;
//        }
//        if(x>ind[mid]){
//            l = mid+1;
//        }
//        if(r-l<=1) return l;
//    }
//}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    ind[1] = 1;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        ind[i+1] = ind[i]+a[i];
    }
    long long x = 250;
    long long mid = l/2-1,ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=a[i];j++) s+=c[i];
    }
    for(int i = 0;i<=mid;i++){
        if(s[opp(i)]!=s[i]) ans++;
    }
    cout<<ans;
    //woxiangnadianfen.duiwohaoyidianba
 //   for(long long i = 0;i<=mid;i++){
 //       int x = check(opp(i));
 //       cout<<i<<" "<<opp(i)<<" "<<x<<" "<<c[x]<<endl;
 //       if(c[x]==c[i]) continue;
 //       ans++;
 //   }
 //   cout<<ans;

    return 0;
}
