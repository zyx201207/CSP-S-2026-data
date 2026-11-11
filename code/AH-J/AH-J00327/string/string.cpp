#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
char c[100010];
signed main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,sum=0,cnt=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        if(c[i]!=c[i+1]){
            cnt++;
        }
        a[cnt]+=a[i+1];
    }
    int l=1,r=cnt;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]>=a[r]){
                a[l]-=a[r];
                sum+=a[r];
                r--;
                if(a[l]==0){
                    l++;
                }
            }else{
                a[r]-=a[l];
                sum+=a[l];
                l++;
                if(a[r]==0){
                    r--;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
