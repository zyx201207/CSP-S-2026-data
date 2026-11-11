#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000+10];
long long cnt[300000+10],ans[300000+10];
void cz(long long x){
    memset(cnt,0,sizeof(cnt));
    stack<long long>st;
    for(long long i=x;i<=n;i++){
        long long k=a[i];
        if(cnt[k]!=0){
            while(st.top()!=k){cnt[st.top()]--;st.pop();}
        }else{
            st.push(k);
            cnt[k]++;
        }
    }
    while(!st.empty()){
        long long t=st.top();
        st.pop();
        ans[t]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)cz(i);
    for(long long i=1;i<=m;i++)printf("%lld ",ans[i]);
    return 0;
}
