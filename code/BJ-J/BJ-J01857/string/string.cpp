#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
string nums;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        long long t;
        cin>>t;
        char c;
        cin>>c;
        for(int i=0;i<t;i++){
            nums.push_back(c);
        }
    }
    int len=nums.size();
    if(len%2==0){
        int l=0,r=len-1;
        while(nums[l]!=nums[r]){
            if(l!=r){
                ans++;
            }
            l++;
            r--;
        }
    }
    else{
        int l=0,r=len-1;
        while(l<=r){
            if(nums[l]!=nums[r]){
                ans++;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
