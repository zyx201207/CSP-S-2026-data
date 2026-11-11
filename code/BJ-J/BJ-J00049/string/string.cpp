#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long a[N];
char s[N];
int n=3;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i] >> s[i];
    }
    int l=0,r=n-1;
    while(l<r) {
        int t=r;
        long long u=a[l];
        while(u>0){
            if (a[t]<=u) {
                if (s[l]!=s[t]) ans+=a[t];
                u-=a[t];
                t--;
                r--;
            }else {
                int c = a[t]-u;
                if (s[l]!=s[t]) ans+=u;
                a[t]=c;
                u=0;
            }
        }
        l++;
    }
    cout<<ans<<endl;
    return 0;
}
