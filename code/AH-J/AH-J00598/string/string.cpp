#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int ans = 0;
    int a[200001];
    char b[200001];
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int l = 0;
    int r = n;
    while(l<r){
        if(a[l]>a[r]){
            if(b[l]!=b[r]){
                ans+=a[l]-a[r];
            }
            a[l]-=a[r];
            r--;
        }
        if(a[l]<a[r]){
            if(b[l]!=b[r]){
                ans+=a[r]-a[l];
            }
            a[r]-=a[l];
            l++;
        }
        if(a[l]=a[r]){
            if(b[l]!=b[r]){
                ans+=a[r];
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
