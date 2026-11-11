#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=550000;
LL m,n,a[N],ans[N];
stack <LL> st;
bool b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            LL cmp=a[j];
            while(b[cmp]){
                LL cmp_f=st.top();
                b[cmp_f]=0;
                st.pop();
            }
            b[cmp]=1;
            st.push(cmp);
        }
        while(st.size()){
            LL cmp_f=st.top();
            b[cmp_f]=0;
            ans[cmp_f]++;
            st.pop();
        }
        /*for(int i=1;i<=m;i++){
            printf("%lld ",ans[i]);
        }
        cout<<endl;*/
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}

