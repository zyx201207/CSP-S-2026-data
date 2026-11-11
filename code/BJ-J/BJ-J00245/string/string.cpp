#include<iostream>
#include<stdio.h>
long long n,ans=0;
long long a[200005];
char ch[200005];
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t=0;cin>>t;
        for(int i=1;i<=t;i++){
        long long x;char y;
        cin>>x>>y;
            if(ch[i-1]==y) a[i-1]+=x,i--,t--;
            else ch[i]=y,a[i]=x;
        n+=x;
        }
    ans=n/2+n%2;
        //for(int i=1;i<=t;i++) cout<<a[i]<<'-'<<ch[i]<<endl;
    long long L=1,l=1,mid=0,R=t,r=1,pdlr=0;
        if(L==R) {cout<<0<<endl;return 0;}
        while(L<=R){
        mid=min(a[L]-l,a[R]-r);
        l+=mid,r+=mid;
            if(ch[L]==ch[R]) ans-=mid;//cout<<ch[L]<<' '<<ch[R]<<' '<<ans<<endl;
            if(l>=a[L]) l=l-a[L],L++;
            if(r>=a[R]) r=r-a[R],R--;
            if(L==R) pdlr=1;
        }
    cout<<ans+pdlr*mid/2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
