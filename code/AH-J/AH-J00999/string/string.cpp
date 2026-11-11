#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=2e5+5;
char a[dd];
long long n,cnt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int r=0,l=0;
    string s;
    while(n--){
        long long x;
        char y;
        cin>>x>>y;
        l+=x;
        for(int i=r;i<=l;i++)a[i]=y;
        r+=x;
    }
    r=1;
    int sum=l;
    while(r<=l){
        if(a[r]!=a[l])cnt++;
        r++,l--;
    }
    cout<<cnt;
}
