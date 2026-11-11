#include<bits/stdc++.h>
using namespace std;
string s="", u;
long long len, n, mid, ans=0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        cin>>len>>u;
        for(long long i=0;i<len;i++){
            s+=u;
        }
    }
    len=s.length();
    if(len%2==1){
        mid=(len-1)/2;
        for(int i=1;i<=mid;i++){
            if(s[mid-i]!=s[mid+i]){
                ans++;
            }
        }
    } else {
        mid=len/2-1;
        for(int i=0;i<=mid;i++){
            if(s[mid-i]!=s[mid+1+i]){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}