#include <bits/stdc++.h>
using namespace std;
//char s[2147300002];
char s[524288000];//hyw200000000000002这内存都存不下啊
int n;
long long a,cnt,ans;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int j=cnt;j<cnt+a;j++)
        {
            s[j]=c;
        }
        cnt+=a;
    }

    for(int i=0;i<=(cnt-1)/2;i++)
    {
        ans+=(int)(s[i]!=s[cnt-1-i]);
    }
    cout <<ans;
    fclose(stdin);
    fclose(stdout);
}
