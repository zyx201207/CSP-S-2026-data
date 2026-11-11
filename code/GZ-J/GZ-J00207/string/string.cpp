// GZ-J00207 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;

constexpr int N=200005;
int a[N];string c[N];
int main()
{
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    /*先把双指针写出来
    string s;cin>>s;int n=s.size();
    int l=0,r=n-1,cnt=0;
    while(l<=r)
    {
        if(s[l]!=s[r]) cnt++;
        l++,r--;
    }
    cout<<cnt;
    return 0;
    */
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;long long cnt=0;
    while(l<=r)
    {
        if(a[l]>a[r]) {if(c[l]!=c[r]) cnt+=a[r];a[l]-=a[r],r--;}
        else if(a[l]<a[r]) {if(c[l]!=c[r]) cnt+=a[l];a[r]-=a[l],l++;}
        else if(a[l]==a[r]) {if(c[l]!=c[r]) cnt+=a[l];l++,r--;}
    }
    cout<<cnt;
    return 0;
}

