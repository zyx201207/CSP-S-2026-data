#include<bits/stdc++.h>
using namespace std;
int ans[500005],a[500005];
int main(){
    a[0]=INT_MIN;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mm;
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int m=mm;
        for(int j=i;a[j]>=a[1];j--){
            if(m>=a[i]-a[j]){
                m-=a[i]-a[j];
                ans[i]++;
            }
            else{
                break;
            }
        }
    }
    int ansl=-0x3f;
    for(int i=1;i<=n;i++){
        ansl=max(ans[i],ansl);
    }
    cout<<ansl;
    return 0;
} 