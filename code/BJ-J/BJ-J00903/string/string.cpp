#include<bits/stdc++.h>
using namespace std;
long long n,a[351599],ans;
char b[351599];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int l = 1,r = n;
    while (l<r){
        if (a[l]<a[r]){
            if (b[l] == b[r]){
                a[r]-=a[l];
                l++;
            }else{
                a[r] -= a[l];
                ans += a[l];
                l++;
            }
        }else if (a[l]>a[r]){
            if (b[l] == b[r]){
                a[l] -= a[r];
                r--;
            }else{
                a[l]-=a[r];
                ans += a[r];
                r--;
            }
        }else{
            if (b[l] == b[r]){
                l++;
                r--;
            }else{
                ans+=a[l];
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
