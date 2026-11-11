#include <bits/stdc++.h>

using namespace std;

inline long long read(){
    long long f=1,sum=0;
    char c=getchar();
    while(!(c<='9'&&c>='0')){if(c=='-')f=-1;c=getchar();}
    while(c<='9'&&c>='0'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
struct node{
    int a,b;
}c[200005];
long long sum[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    n=read();
    long long x;
    char ch;
    long long len = 0;
    for(int i=1;i<=n;i++){
        x=read();
        cin>>ch;
        len+=x;
        c[i].a=x;
        c[i].b=(ch-'a'+1);
        sum[i]=sum[i-1]+c[i].a;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(len<=500){
        string s=" ";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c[i].a;j++)s+=char(c[i].b+'a'-1);
        }
        long long ans=0;
        for(int i=1;i<=(len+1)/2;i++){
            if(s[i]!=s[len-i+1])ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    int l=1,r=n;
    long long tot=0;
    long long ans=0;
    long long s1 = c[1].a;
    long long s2 = c[n].a;
    bool flag=false;
    while(1){
        if(tot+s1>=len/2){
            while(1){
                if(l==r){
                    flag=true;
                    break;
                }
                tot+=s2;
                ans+=s2;
                s1 = s1-s2;
                r--;
                s2 = c[r].a;
            }
        }
        if(flag)break;
        if(c[l].b!=c[r].b){
            if(s1>s2){
                tot+=s2;
                ans+=s2;
                s1 = s1-s2;
                r--;
                s2 = c[r].a;
            }else if(s1<s2){
                tot+=s1;
                ans+=s1;
                s2 = s2-s1;
                l++;
                s1 = c[l].a;
            }else{
                tot+=s2;
                ans+=s2;
                l++;
                r--;
                s2 = c[r].a;
                s1 = c[l].a;
            }
        }else{
            if(s1>s2){
                tot+=s2;
                s1 = s1-s2;
                r--;
                s2 = c[r].a;
            }else if(s1<s2){
                tot+=s1;
                s2 = s2-s1;
                l++;
                s1 = c[l].a;
            }else{
                tot+=s2;
                l++;
                r--;
                s2 = c[r].a;
                s1 = c[l].a;
            }
        }
    }
    cout<<ans;
    return 0;
}
