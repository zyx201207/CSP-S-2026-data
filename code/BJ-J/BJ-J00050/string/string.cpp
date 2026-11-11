#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,ans;
int num[200005];
int lft[200005];
int rgt[200005];
vector<int> nums;
vector<int> tmp;
vector<int> ls;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        int l=sum+1;
        int r=sum+a;
        sum+=a;
        num[i]=b-'a';
        lft[i]=l;
        rgt[i]=r;
        tmp.push_back(l);
        tmp.push_back(r);
        ls.push_back(l);
    }
    for(int i=1;i<=n;i++){
        tmp.push_back(sum+1-lft[i]);
        tmp.push_back(sum+1-(lft[i+1]-1));
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++){
        if(i==0 || tmp[i]!=tmp[i-1]){
            nums.push_back(tmp[i]);
        }
    }
    int l=1,r=n;
    for(int i=0;i<nums.size();i++){

        int a=nums[i],b=sum+1-nums[i];
        if(a>rgt[l])
            l++;
        if(b<lft[r])
            r--;
        int pos1=l;
        int pos2=r;
        if(num[pos1]==num[pos2]){
            continue;
        }
        if(i==nums.size()-1){
            ans+=sum-nums[i]+1;
        }
        else{
            ans+=nums[i+1]-nums[i];
        }
    }
    cout<<ans/2;
    return 0;
}
