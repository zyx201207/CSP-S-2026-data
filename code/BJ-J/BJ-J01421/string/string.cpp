#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;
char c[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long len=s.length();
    if(len%2==1){
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-1-i])
                cnt++;
        }

    }else{
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-1-i])
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
