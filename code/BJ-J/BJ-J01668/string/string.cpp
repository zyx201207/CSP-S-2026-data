#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],tops,topd,cnt1,cnt2,ans;char s[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    tops=0,topd=n+1;
    for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
    while(topd-tops>1){
        if(cnt1>0){
            topd--;
            cnt2+=a[topd];
            long long cntm=min(cnt1,cnt2);
            if(s[tops]!=s[topd])ans+=cntm;
            cnt1-=cntm;cnt2-=cntm;
        }
        else if(cnt2>0){
            tops++;
            cnt1+=a[tops];
            long long cntm=min(cnt1,cnt2);
            if(s[tops]!=s[topd])ans+=cntm;
            cnt1-=cntm;cnt2-=cntm;
        }
        else if(tops==topd+2)break;
        else {
            topd--;
            cnt2+=a[topd];
            tops++;
            cnt1+=a[tops];
            long long cntm=min(cnt1,cnt2);
            if(s[tops]!=s[topd])ans+=cntm;
            cnt1-=cntm;cnt2-=cntm;
        }
    }
    cout<<ans;
    return 0;
}
