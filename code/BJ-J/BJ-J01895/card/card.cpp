#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int mark[200010];
int ans[200010];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<a[i-1]) flag=false;
    }
    if(flag==true){
        for(int i=n;i>=1;i--){
            if(ans[a[i]]==0)
                ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++)
            printf("%d ",ans[i]);
    }
    else{

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                mark[j]=0;

            for(int j=i;j<=n;j++){
                if(mark[a[j]]==1){
                    while(st.top()!=a[j]){
                        mark[st.top()]=0;
                        st.pop();
                    }
                }else{
                    st.push(a[j]);
                    mark[a[j]]=1;
                }
            }

            while(!st.empty()){
                ans[st.top()]++;
                st.pop();
            }

        }

        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
    }

}
