#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }

    }
    int len=s.length();
    int right=len-1;
    int left=0;
    while(left!=right){
        if(right-left==1) break;
        if(s[left]!=s[right]){
            ans++;
        }
        right--;
        left++;
    }
    cout<<ans;
    return 0;
}
