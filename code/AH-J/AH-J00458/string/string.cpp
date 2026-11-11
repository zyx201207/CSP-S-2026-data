#include<bits/stdc++.h>
using namespace std;
long long n,num[250005],mx=-0x3f3f3f3f3f3f3f3f;
char c[250005];
int b[512];
long long max(long long x,long long y)
{
    return (x>y?x:y);
}
long long min(long long x,long long y)
{
    return (x<y ? x : y);
}
int main()
{
    //freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>num[i]>>c[i];
        mx=max(num[i],mx);
        b[c[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=500;i++)
    {
        if(b[i]>0)cnt++;
    }
    if(cnt==1)cout<<0;
    else if(cnt==2)
    {
        long long ans1,ans2;
        char a;
        a=c[1];
        for(long long i=1;i<=n;i++)
        {
            if(c[i]!=a)
            {
                ans2+=num[i];
            }else{
                ans1+=num[i];
            }
        }
        cout<<min(ans1,ans2);
    }
    else cout<<mx;
	return 0;
}