#include<bits/stdc++.h>
using namespace std;
int n,l=0,r;
long long a[200005],step;
char s[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n-1;
    for(int i=0;i<n;i++) cin>>a[i]>>s[i];
    while(l<=r){
        if(s[l]!=s[r]){
            if(a[l]==a[r]){
                step+=a[r];
                a[l]=a[l]-a[r];
                r--;l++;
            }else if(a[l]<a[r]){
                step+=a[l];
                a[r]=a[r]-a[l];
                l++;
            }else{
                step+=a[r];
                a[l]=a[l]-a[r];
                r--;
            }
        }else{
            if(a[l]==a[r]){
                a[l]=a[l]-a[r];
                r--;
                l++;
            }else if(a[l]<a[r]){
                a[r]=a[r]-a[l];
                l++;
            }else{
                a[l]=a[l]-a[r];
                r--;
            }
        }
    }
    cout<<step;
    return 0;
}
