#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long left=1,right=n;
    long long ans=0;
    while(left<right){
        if(b[left]!=b[right]){
            ans+=min(a[left],a[right]);
        }
        if(a[left]>a[right]){
            a[left]-=a[right];
            right--;
        }
        else if(a[left]==a[right]){
            left++;
            right--;
        }
        else{
            a[right]-=a[left];
            left++;
        }
    }
    cout<<ans;
    return 0;
}
