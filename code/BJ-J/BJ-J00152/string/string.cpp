#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[30];
string s;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        char c;
        cin>>a>>c;
        while(a--) s+=c;
    }
    ll len=s.size();
    bool ok=true;
    if(len%2==0) {
        for(int i=0;i<len/2;i++) {
            if(s[i]!=s[len-1-i]) ok=false;
        }
    } else {
        for(int i=0;i<len/2;i++) {
            if(s[i]!=s[len-1-i]) ok=false;
        }
    }
    if(ok) {
        cout<<0;
        return 0;
    }
    ll sum=0;
    for(int i=0;i<len;i++) {
        a[(int)s[i]-97]++;
        sum++;
    }
    int maxn=-1;
    for(int i=0;i<26;i++) {
        if(a[i]>maxn) maxn=a[i];
    }
    cout<<sum-maxn;
    return 0;
}
