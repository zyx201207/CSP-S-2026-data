#include <bits/stdc++.h>
using namespace std;
char s[2000005];
int n,all;
bool q=true;
char aa[2000005];
long long int a[2000005]={0},ans=0;
void d(int i,int j)
{
    if (i==0)
    {
        return;
    }
    if (s[i]==s[j])
    {
        d(i-1,j+1);
    }
    else {ans++;d(i-1,j+1);}
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> aa[i];
        all+=a[i];
        for (int j=all-a[i]+1;j<=all;j++) s[j]=aa[i];
    }
    if (all%2==0) q=false;
    int mid;
    if (q)
    {
        mid=all/2+1;
        d(mid,mid);
    }
    else
    {
        mid=all/2;
        d(mid,mid+1);
    }
    cout << ans << endl;
}
