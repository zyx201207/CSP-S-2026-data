#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++)s+=c;
    }
    int ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])ans++;
    }
    cout<<ans;
    return 0;
}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[200011],a1[200011],a2[200011],a1f[200011],a2f[200011],a1ff[200011],a2ff[200011],ta,tb;
//int lsh[200011],tp;
//char c[200011],c1[200011],c2[200011];
//signed main()
//{
//    //freopen("string5.in","r",stdin);
//    //freopen("string.out","w",stdout);
//    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    int n,cnt=0,ans=0;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i]>>c[i];
//        cnt+=a[i];
//    }
//    for(int i=1,sum=0;i<=n;i++)
//    {
//        sum+=a[i];
//        if(sum>=(cnt/2))
//        {
//            a1[++ta]=(cnt/2)-sum+a[i];
//            c1[ta]=c[i];
//            break;
//        }
//        a1[++ta]=a[i];
//        c1[ta]=c[i];
//    }
//    for(int i=n,sum=0;i>=1;i--)
//    {
//        sum+=a[i];
//        if(sum>=(cnt/2))
//        {
//            a2[++tb]=(cnt/2)-sum+a[i];
//            c2[tb]=c[i];
//            break;
//        }
//        a2[++tb]=a[i];
//        c2[tb]=c[i];
//    }
//    for(int i=1;i<=ta;i++)
//    {
//        a1f[i]=a1f[i-1]+a1[i];
//        lsh[++tp]=a1f[i];
//    }
//    for(int i=1;i<=tb;i++)
//    {
//        a2f[i]=a2f[i-1]+a2[i];
//        lsh[++tp]=a2f[i];
//    }
//    sort(lsh+1,lsh+tp+1);
//    tp=unique(lsh+1,lsh+tp+1)-lsh;
//    for(int i=1;i<=ta;i++)
//    {
//        a1ff[i]=lower_bound(lsh+1,lsh+tp+1,a1f[i])-lsh;
//    }
//    for(int i=1;i<=tb;i++)
//    {
//        a2ff[i]=lower_bound(lsh+1,lsh+tp+1,a2f[i])-lsh;
//    }
//    //for(int i=1;i<=ta;i++)cout<<a1f[i]<<" ";
//    //cout<<"\n";
//    //for(int i=1;i<=tb;i++)cout<<a2f[i]<<" ";
//    for(int i=1,n1=1,n2=1;i<=tp;i++)
//    {
//        if(a1ff[n1]==i&&a2ff[n2]==i)
//        {
//            if(c1[n1]!=c2[n2])ans+=min(a1[n1],a2[n2]);
//            n1++;
//            n2++;
//        }
//        else if(a1ff[n1]==i)
//        {
//            if(c1[n1]!=c2[n2])ans+=a1f[n1]-a2f[n2-1];
//            n1++;
//        }
//        else
//        {
//            if(c1[n1]!=c2[n2])ans+=a2f[n2]-a1f[n1-1];
//            n2++;
//        }
//    }
//    cout<<ans;
//    return 0;
//}
