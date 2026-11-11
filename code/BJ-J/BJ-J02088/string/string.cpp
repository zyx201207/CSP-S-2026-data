#include<bits/stdc++.h>
using namespace std;
int a[200005];char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    long long len=0,coui=0,couj=0,coji,ans=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
    //cout<<len<<endl;
    for(int i=1,j=n;i<=j;i++)
    {
        coui+=a[i];
        while(couj+a[j]<=coui&&j>=i)//zheng
        {
            couj+=a[j];//cout<<couj<<endl;
            if(c[j]!=c[i])ans+=a[j];
            j--;
        }
        //cout<<coui<<" "<<couj<<endl;//fen
        if(c[j]!=c[i])ans+=coui-couj;
        a[j]-=(coui-couj);couj=coui;
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
