#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+5;

struct Node{
    int i;
    char c;
}a;
string s="";

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,zong=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a.i>>a.c;
        for(int j=1;j<=a.i;j++){
            s+=a.c;
        }
    }
    zong=s.size();
    int zon=zong/2;
    int cnt=0;
    for(int i=0;i<=zon;i++){
        int j=zong-zon-1;
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
}
