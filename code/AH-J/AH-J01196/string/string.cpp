#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long cnt=0;
    int left=1,right=n;
    while(left<right){
        int _min=min(a[left],a[right]);
        if(c[left]==c[right]){
            a[left]-=_min;
            a[right]-=_min;
            if(a[left]==0)left++;
            if(a[right]==0)right--;
        }else{
            a[left]-=_min;
            a[right]-=_min;
            cnt+=_min;
            if(a[left]==0)left++;
            if(a[right]==0)right--;
        }
    }cout<<cnt;
    return 0;
}
