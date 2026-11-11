///今年的j1分数线低亿点吧！！！！！！！！最好今年全爆0，一等50分 大佬们保佑我啊，我只是一个蒻芨啊啊啊啊
///不不不不不不不不不不不不我居然做出来了我无疑是兴奋的
///个屁啊我哪做出来了啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e7+5;
unsigned long long n,a[N],cnt=1,ans=0,c[N];
char s[200005];
bool flag=true;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    char p=s[1];
    for(ll i=2;i<=n;i++){
        if(p!=s[i])flag=false;
    }
    if(n==1||flag==true){
        cout<<0<<"\n";
        return 0;
    }
    else {
        for(ll i=1;i<=n/2;i++){
            if(s[i]==s[n-i+1]){
                if(a[i]>a[n-i+1])ans+=a[i]-a[n-i+1];
                else ans+=a[n-i+1]-a[i];
            }
            else {
                ans+=max(a[i],a[n-i+1]);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
