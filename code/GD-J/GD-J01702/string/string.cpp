#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
            s+=b;
    }
    int len=s.size();
    int l=0,r=len;
    while(l<=len){
        if(s[l]!=s[r-1])
            ans++;
        l++;
        r--;
    }
    return 0;
}
