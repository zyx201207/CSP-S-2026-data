#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt=0,j;
string c[200005];
void solve(){
    cin>>n;
    j=n-1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<j;i++){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                cnt+=a[j];
                j--;
                i--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                cnt+=a[i];
            }else{
                cnt+=a[j];
                j--;
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
                i--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
            }else{
                j--;
            }
        }
    }
    cout<<cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}
