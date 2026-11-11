#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],cnt[300005];
stack<int> st;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(long long j=i;j<=n;j++){
            if(!b[a[j]]){
                st.push(a[j]);
                b[a[j]]=1;
            }else{
                while(true){
                    b[st.top()]=0;
                    st.pop();
                    if(st.top()==a[j]){
                        break;
                    }
                }
            }
        }
        for(long long j=1;j<=m;j++){
            if(b[j]) cnt[j]++;
        }
        while(!st.empty()){
            st.pop();
        }
    }
    for(long long i=1;i<=m;i++){
        printf("%lld ",cnt[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
