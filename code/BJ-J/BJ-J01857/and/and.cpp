#include <bits/stdc++.h>
using namespace std;
int n,m;
long long nums[100005];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            if(nums[i]>ans){
                ans=nums[i];
            }
        }
    }
    if(m==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]&nums[j]>ans){
                    ans=nums[i]&nums[j];
                }
            }
        }
    }
    if(m==n){
        ans=nums[0];
        for(int i=1;i<n;i++){
            ans=ans&nums[i];
        }
    }
    cout<<ans;
    return 0;
}
