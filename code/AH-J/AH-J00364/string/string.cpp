#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a;
char c;
string s;
void f(string s){
     int l=0,cnt=0;
     int r=s.size()-1;
     cout<<s[l]<<" "<<s[r];
     while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }l++;
        r--;
     }cout<<cnt;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
           s=s+c;
        }
    }f(s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

