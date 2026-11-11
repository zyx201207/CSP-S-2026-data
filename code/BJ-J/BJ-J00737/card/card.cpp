#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        stack<int> st;
        while(st.size())st.pop();
        for(int j=1;j<=m;j++)vis[j]=0;
        for(int j=i;j<=n;j++){
            //cout<<a[j]<<" ";
            if(vis[a[j]]==1){

                while(st.size()&&st.top()!=a[j]){/*cout<<a[j]<<"&"<<st.top()<<" ";*/vis[st.top()]=0;st.pop();}
                //cout<<a[j]<<"&"<<a[j]<<" ";
            }else{
                vis[a[j]]=1;
                st.push(a[j]);
            }
        }
        //cout<<endl<<"*";
        while(st.size()){
            ans[st.top()]++;
            //cout<<st.top()<<" ";
            st.pop();
        }
        //cout<<endl;
        //cout<<"*"<<q.size()<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
