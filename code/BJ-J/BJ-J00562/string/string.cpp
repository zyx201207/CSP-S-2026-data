#include<bits/stdc++.h>
using namespace std;
char s[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,tot = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j = 0;j<a;j++){
            s[tot+j] = c;
        }
        tot += a;
    }
    int l = 0,r = tot-1,cnt = 0;
    while(l<r){
        if(s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}