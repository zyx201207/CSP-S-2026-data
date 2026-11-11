#include<bits/stdc++.h>
using namespace std;
int a[200020];
char c[200020];
int ta[200020];
char tc[200020];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long big=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        big+=a[i];
    }
    for(int i=n;i>=1;i--)
        ta[i]=a[n-i+1];
    for(int i=n;i>=1;i--)
        tc[i]=c[n-i+1];
    long long cnta=0,cntt=0,pa=1,pt=1,cnt=0;
    for(long long i=1;i<=big;i++){
        cnta++;
        cntt++;
        if(c[pa]!=tc[pt])
            cnt++;
        if(cnta>=a[pa]){
            cnta=0;
            pa++;
        }
        if(cntt>=ta[pt]){
            cntt=0;
            pt++;
        }
    }
    cout<<cnt/2;

    return 0;
}
