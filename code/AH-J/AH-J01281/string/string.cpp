#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
ll s1[N],s2[N],sum,a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool f=true;
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        if(i>1&&c[i]!=c[i-1])f=false;
        sum+=a[i];
        s1[i]=s1[i-1]+a[i-1];
    }
    if(f){
        cout<<0;
        return 0;
    }
    for(int i=n-1;i>=1;i--)s2[i]=s2[i+1]+a[i+1];
    ll l=1,L=1,R=n,r=1,cnt=0;
    while(l<=sum/2&&r<=sum/2){
        while(c[L]!=c[R]&&s1[L+1]<s2[R-1])l=r=s1[++L]+1;
        while(c[L]!=c[R]&&s1[L+1]>s2[R-1])l=r=s2[--R]+1;
        while(s1[L+1]<l)L++;
        while(s2[R-1]<r)R--;
        if(c[L]==c[R]){
                ll s=0;
            if(s1[L+1]==s2[R-1])s=min(a[L],a[R]),l=r=s2[--R]+1,L++;
            else if(s1[L]>=s2[R]&&s1[L]<s2[R-1]&&s1[L+1]>=s2[R-1])s=a[R]-(s1[L]-s2[R]+1),l=r=s2[--R]+1;
            else if(s1[L]<=s2[R]&&s1[L+1]>s2[R]&&s1[L+1]<=s2[R-1])s=a[L]-(s2[R]-s1[L]+1),l=r=s1[++L]+1;
            else if(s1[L]<=s2[R]&&s1[L+1]>=s2[R-1])s=a[R],l=r=s2[--R]+1;
            else if(s1[L]>=s2[R]&&s1[L+1]<=s2[R-1])s=a[L],l=r=s1[++L]+1;
            cnt+=s;
        }else{
            if(s1[L+1]<s2[R-1])l=r=s1[++L]+1;
            else if(s1[L+1]>s2[R-1])l=r=s2[--R]+1;
            else l=s1[++L]+1,r=s2[--R]+1;
        }
    }
    cout<<sum/2-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
