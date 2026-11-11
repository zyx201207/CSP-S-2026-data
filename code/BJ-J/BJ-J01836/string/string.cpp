#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct c{
    long long num;
    char ch;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>s[i].num>>s[i].ch;
    }
    for(long long l=1,r=n;l<r;){
        if(r-l==1&&s[l].num==s[r].num)break;
        long long x=min(s[l].num,s[r].num);
        if(s[l].ch!=s[r].ch)ans+=x;
        s[l].num-=x;
        s[r].num-=x;
        if(s[l].num==0)l++;
        if(s[r].num==0)r--;
    }
    cout<<ans;
}
