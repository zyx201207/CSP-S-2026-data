#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<long long> a(n);
    vector<char> c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n-1;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                ans+=a[l];
                r--;
                l++;
            }else{
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                r--;
                l++;
            }else{
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
