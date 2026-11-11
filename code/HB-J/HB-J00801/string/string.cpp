#include<bits/stdc++.h>
using namespace std;
long long t1[30],t2[30];
long long ans;
string ss;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(int i=1;i<=x;i++)
        {
            ss+=c;
        }
    }
    long long len=ss.size();
    long long mid=len/2;
    for(long long i=0;i<mid;i++)
    {
        t1[ss[i]-'a'+1]++;
    }
    for(long long i=mid+1;i<len;i++)
    {
        t2[ss[i]-'a'+1]++;
    }
    for(int i=1;i<=30;i++)
    {
        if((ans+abs(t1[i]-t2[i]))<=len/2) ans+=abs(t1[i]-t2[i]);
    }
    cout<<ans;
    return 0;
}