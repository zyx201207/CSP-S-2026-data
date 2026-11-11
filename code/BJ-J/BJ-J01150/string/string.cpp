#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
long long a[200010];
char c[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]<=a[r]){
                t+=a[l];
                a[r]-=a[l];
                l++;
            }else{
                t+=a[r];
                a[l]-=a[r];
                r--;
            }
        }else{
            if(a[l]<=a[r]){
                a[r]-=a[l];
                l++;
            }else{
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<t;
    return 0;
}
