#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<ull> nums;
bool cop(ull i,ull j){
    return i>j;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ull n,m;
    cin>>n>>m;
    for(ull i=0;i<n;++i) cin>>nums[i];
    sort(nums.begin(),nums.end(),cop);
    cout<<nums[m-1];
    return 0;
}