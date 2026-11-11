#include<bits/stdc++.h>
using namespace std;
long long n,len,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
       len+=a;
       for(int i=1;i<=a;i++){
        s+=c;
       }
    }
    int l=0,r=len-1;
    while(l<=r){
        if(s[l]==s[r]){
                l++;
                r--;
                continue;
        }else{
        ans++;
        l++;
        r--;
        }
    }
    cout<<ans;
    return 0;
}
