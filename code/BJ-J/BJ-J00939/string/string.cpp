#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,a[N];
ll ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,l=a[1],r=a[n];
    while (i<j){
        while (i<j&&l==r){
            if (c[i]!=c[j]){
                ans+=l;
            }
            i++;
            j--;
            l=a[i],r=a[j];
        }
        if (i==j){
            break;
        }
        while (i<j&&l>r){
            if (c[i]!=c[j]){
                ans+=r;
            }
            j--;
            l-=r;
            r=a[j];
        }
        if (i==j){
            break;
        }
        while (i<j&&l<r){
            if (c[i]!=c[j]){
                ans+=l;
            }
            i++;
            r-=l;
            l=a[i];
        }
    }
    cout<<ans;
    return 0;
}
