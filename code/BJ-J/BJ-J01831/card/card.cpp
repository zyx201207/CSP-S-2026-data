#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
stack<int> st;
bool Y(int x){
    stack<int> stk;
    stk=st;
    while(stk.size()){
        if(stk.top()==x)return true;
        stk.pop();
    }
    return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(Y(a[j])){
                while(st.top()!=a[j])st.pop();
                continue;
            }
            st.push(a[j]);
        }
        int cnt=0;
        while(!st.empty()){
            int hx=st.top();
            cnt++;
            ans[hx]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}
