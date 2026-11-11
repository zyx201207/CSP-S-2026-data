#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
long long h[500005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(st.top()!=a[j]){
                    vis[st.top()]=false;
                    st.pop();
                }
            }else{
                st.push(a[j]);
                vis[a[j]]=true;
            }
        }
        while(st.size()){
            h[st.top()]++;
            vis[st.top()]=false;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<h[i]<<' ';
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int last[500005];
// int h[500005];
// int b[500005];
// int a[500005];
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//     for(int i=1;i<=n;i++)h[a[i]]+=i;
//     for(int i=n;i>=1;i--){
//         if(!last[a[i]])last[a[i]]=i;
//         else{
//             b[i]--;
//             b[last[a[i]]]++;
//         }
//     }
//     for(int i=1;i<=n;i++)b[i]+=b[i-1];
//     for(int i=1;i<=n;i++)h[a[i]]+=b[i];
//     for(int i=1;i<=m;i++)printf("%d ",h[i]);
//     return 0;
// }