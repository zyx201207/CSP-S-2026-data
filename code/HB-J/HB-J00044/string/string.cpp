#include <bits/stdc++.h>
using namespace std;
long long cnt =0;
long long a[100005];
char s[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >>s[i];
    }
    string y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            y+=s[i];
        }
    }
    int len=y.size();
    int l=len/2,r=len/2;
    int t1=0,t2=len-1;
    while(t1<l){
        if(y[t1]!=y[t2]){
            cnt++;
            y[t2]=y[t1];
        }
        t1++;
        t2--;
    }
    cout << cnt ;
    return 0;
}
