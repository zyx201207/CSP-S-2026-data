#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r){
        if(a[l]==a[r]){
            if(c[l]!=c[r]) cnt+=a[l];
            l++,r--;
        }else{
            if(c[l]==c[r]){
                if(a[l]>a[r]) a[l]-=a[r--];
                else a[r]-=a[l++];
            }else{
                if(a[l]>a[r]){
                    a[l]-=a[r];
                    cnt+=a[r];
                    r--;
                }else{
                    a[r]-=a[l];
                    cnt+=a[l];
                    l++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
