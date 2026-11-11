#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("string.in","r",stdin);
#define fout freopen("string.out","w",stdout);
using namespace std;
typedef long long lli;
int n;
lli len,ans;
pair<int,char> a[500005],a1[500005],a2[500005];
int n1,n2;
void divstr()
{
    lli lenn=0;
    for(int i=1;i<=n;i++)
    {
        if(lenn>=len)
            break;
        if(lenn+a[i].first<=len)
        {
            a1[++n1]=a[i];
            lenn+=a[i].first;
        }
        else
        {
            a1[++n1]=make_pair(len-lenn,a[i].second);
            lenn=len;
        }
    }
    lenn=0;
    for(int i=n;i>=1;i--)
    {
        if(lenn>=len)
            break;
        if(lenn+a[i].first<=len)
        {
            a2[++n2]=a[i];
            lenn+=a[i].first;
        }
        else
        {
            a2[++n2]=make_pair(len-lenn,a[i].second);
            lenn=len;
        }
    }
}
signed main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].first >> a[i].second;
        len+=a[i].first;
    }
    len/=2;
    divstr();

    lli len1=0,len2=0;
    int pos1=1,pos2=1;
    while(len1<len || len2<len)
    {
        if(len1<=len2)
        {
            ans+=min(lli(a1[pos1].first),len2-len1)*(a1[pos1].second==a2[pos2-1].second?0:1);
            len1+=a1[pos1++].first;
        }
        else
        {
            ans+=min(lli(a2[pos2].first),len1-len2)*(a2[pos2].second==a1[pos1-1].second?0:1);
            len2+=a2[pos2++].first;
        }
    }
    cout << ans << endl;
    return 0;
}
