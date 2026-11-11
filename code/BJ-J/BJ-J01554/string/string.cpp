#include<bits/stdc++.h>
using namespace std;
long long n,cnt,r,l,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        char c;
        int x;
        cin >> x >> c;
        cnt+=x;
        while(x--)
        {
            s+=c;
        }
    }
    r=0;
    l=cnt-1;
    while(r<l)
    {
        if(s[r]!=s[l])
        {
            ans++;
        }
        r--;
        l++;
    }
    cout<<ans;
    return 0;
}

