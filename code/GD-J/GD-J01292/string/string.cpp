#include<bits/stdc++.h>
using namespace std;
long long n;
long long num[200005],ans=0;
string s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        cin>>s[i];
    }
    long long l=1,r=n;
    while(1==1){
        if(num[l]==0){
            l++;
        }
        if(num[r]==0){
            r--;
        }
        if(s[l]!=s[r]){
            ans++;
        }
        num[l]--;
        num[r]--;
        if(l==r){
            break;
        }
    }
    cout<<ans;
    return 0;
}
