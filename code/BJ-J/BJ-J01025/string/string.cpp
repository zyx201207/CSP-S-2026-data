#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[100005],i,cnt=0,b,l=0,c=0,d,di,sa[100005]={0};
    char s[100005];
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i]>>s[i];l+=a[i];if(i)sa[i]=sa[i-1]+a[i];else sa[i]=a[i];}
    d=l;
    di=n-1;
    for(i=0;i<n&&c<=l/2;c+=a[i++]){
        b=a[i];
        if(d-sa[di-1]>=a[i]){
            d-=a[i];
            if(s[i]!=s[di])cnt+=a[i];
        }
        else{
            d-=a[i];
            for(;sa[di-1]>d;di--)if(s[i]!=s[di])cnt+=min(a[di],sa[di]-d);
        }
    }
    if(c-a[i]!=l-c&&s[i]!=s[i+1])cnt+=abs(c-a[i]-l+c-1);
    cout<<cnt;
    return 0;
}
