#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long t;
    string ans="";
    cin>>t;
    while(t--){
        long long n;
        string s;
        cin>>n>>s;
        for(int i=1;i<=n;i++){
            ans=ans+s;
        }
    }
    long long len=ans.size();
    long long sum=0;
    long long l=0,r=len-1;
    while(l<r){
        if(ans[l]!=ans[r]){
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}
