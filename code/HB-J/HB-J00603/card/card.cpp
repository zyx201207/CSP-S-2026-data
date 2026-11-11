#include<bits/stdc++.h>
using namespace std;
int a[500050],c[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        int b[500050];
        for(int k=0;k<=n;k++) b[k]=0;
        for(int j=i;j<=n;j++){
            if(!st.empty()){
                if(b[a[j]]==1){
                    while(st.top()!=a[j]){
                        b[st.top()]=0;
                        st.pop();
                    }

                }
                else
                {
                    st.push(a[j]);
                    b[a[j]]=1;
                }
            }
            else{
                st.push(a[j]);
                b[a[j]]=1;
            }

        }
        int sum=0;
        while(!st.empty()){
             c[st.top()]++;
            st.pop();
        }

    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
