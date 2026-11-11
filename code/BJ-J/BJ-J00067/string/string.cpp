#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,cnt=0,a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<j){
        if(a[i]==a[j]){
            if(c[i]!=c[j]) cnt+=a[i];
            i++,j--;
        }else if(a[i]<a[j]){
            if(c[i]!=c[j]) cnt+=a[i];
            a[j]-=a[i];
            i++;

        }else{
            if(c[i]!=c[j]) cnt+=a[j];
            a[i]-=a[j];
            j--;
        }
    }
    cout<<cnt;
    return 0;
}
