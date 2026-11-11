#include<bits/stdc++.h>
using namespace std;
string hw,l,r;
unsigned long long r1=0,r2=0,res=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        char c;
        cin>>c;
        for(int j=0;j<a;j++)
        {
            hw+=c;
        }
    }
    if(hw.size()%2==0)
    {
        int mid=hw.size()/2;
        for(int i=mid-1;i>=0;i--) l+=hw[i];
        for(int i=hw.size()-1;i>=mid;i--) r+=hw[i];
        for(int i=0,j=mid;i<mid,j<hw.size();i++,j++)
        {
            if(hw[j]!=l[i]) r1++;
            if(hw[i]!=r[i]) r2++;
        }
        res=min(r1,r2);
    }
    else
    {
        int mid=hw.size()/2;
        for(int i=mid-1;i>=0;i--) l+=hw[i];
        for(int i=hw.size()-1;i>mid;i--) r+=hw[i];
        for(int i=0,j=mid+1;i<mid,j<hw.size();i++,j++)
        {
            if(hw[j]!=l[i]) r1++;
            if(hw[i]!=r[i]) r2++;
        }
        res=min(r1,r2);
    }
    cout<<res;

    return 0;
}
