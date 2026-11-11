// #include <bits/stdc++.h>
// using namespace std;
// int n,m;
// int a[500010];
// int ans[300010];
// int t[300010];
// bool flag[300010];
// bool flagl[300010];
// int main(){
//     freopen("card.in","r",stdin);
//     freopen("card.out","w",stdout);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     for(int i=1;i<=n;i++){
//         memset(t,0,sizeof(t));
//         memset(flag,false,sizeof(flag));
//         memset(flagl,false,sizeof(flagl));
//         //find pre
//         for(int j=i;j<=n;j++){
//             if(flag[a[j]]==false){
//                 flag[a[j]]=true;
//                 t[j]=true;
//             }
//         }
//         //find end
//         for(int j=n;j>=i;j--){
//             if(!flagl[a[j]]&&t[j]==0){
//                 flagl[a[j]]=true;
//                 t[j]=false;
//             }
//         }
//         //sum
//         for(int j=i;j<=n;j++){
//             cout<<t[i]<<" ";
//             t[i]=t[i-1]&t[j];
//         }
//         cout<<endl;
//         //find 0;
//         for(int j=i;j<=n;j++){
//             if(t[j]==0){
//                 ans[a[j]]++;
//             }
//         }
//     }
//     for(int j=1;j<=m;j++){
//         cout<<ans[j]<<" ";
//     }
// }
//烦人的T4啊啊啊 作不出来了aaaaaaaa
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
bool t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        //fa～pai!
        stack<int> st;
        memset(t,false,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]){
                int stt=st.top();
                while(stt!=a[j]){
                    t[stt]=false;
                    st.pop();
                    stt=st.top();
                }
                st.pop();
            }
            st.push(a[j]);
            t[a[j]]=true;
        }
        for(int j=1;j<=m;j++){
            if(t[j]==true){
                ans[j]++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
}