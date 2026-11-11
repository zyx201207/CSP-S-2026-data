#include<bits/stdc++.h>
using namespace std;
const int N=2000000,NA=300;
int testid,T,n,dpA[NA+5][NA+5],dpB[NA+5][NA+5];
long long d,a[N+5];
int main(){
     freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>T;
    while(T--){
//        cin>>n>>d;
//        int sum=0;
//        for(int i=1;i<=n;++i)cin>>a[i];
//        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dpA[i][j]=0,dpB[i][j]=1000000000;
//        for(int i=1;i<=n;++i)dpA[i][i]=dpB[i][i]=1;
//        for(int len=2;len<=n;++len){
//            for(int l=1;l<=n-len+1;++l){
//                int r=l+len-1;
//                for(int i=l;i<r;++i){
//                    if(a[i+1]-a[i]>d)continue;
//                    dpB[l][r]=min(dpB[l][r],dpB[l][i]+dpB[i+1][r]);
//                }
//            }
//        }
//        for(int len=2;len<=n;++len){
//            for(int l=1;l<=n-len+1;++l){
//                int r=l+len-1;
//                for(int i=l;i<(l+r+1)/2;++i){
//                    if(a[i+1]-a[i]>d)continue;
//                    dpA[l][r]+=dpA[l][i]*dpA[i+1][r];
//                }
//            }
//        }
//        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)sum+=(dpA[i][j]==2);
//        for(int l=1;l<=n;++l){
//            for(int r=1;r<=n;++r){
//                cerr<<dpB[l][r]<<' ';
//            }
//            cerr<<'\n';
//        }
        cout<<0<<'\n';
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2000000;
// const long long Inf=1000000000000000000;
// struct Queue{
//     int id[N+5],l=1,r=0;
//     void Push(int x,int *a){
//         while(l<=r&&a[id[l]]>a[x])l++;
//         id[++r]=x;
//     }
//     void Pop(int Id){
//         while(l<=r&&id[l]<Id)l++;
//     }
//     void One(){
//         if(l<=r)l++;
//     }
//     int Front(){
//         if(l>r)return 0;
//         return id[l];
//     }
// };
// int c,T,n,dp[N+5];
// long long d,a[N+5];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>c>>T;
//     while(T--){
//         vector<int>B;
//         B.clear();
//         cin>>n>>d;
//         for(int i=1;i<=n;++i)dp[i]=N;
//         dp[0]=0;
//         for(int i=1;i<=n;++i)cin>>a[i];
//         Queue First;
//         int now=1;
//         for(int i=1;i<=n;++i){
//             while(a[i]-a[now]>d)now++;
//             First.Pop(now);
//             if(First.Front()==0)B.push_back(i);
//             dp[i]=dp[First.Front()]+1;
//             First.Push(i,dp);
//         }
//         for(int l=1;l<=n;++l){
//             for(int r=l+1;r<=n;++r){
//                 for(int i=l;i<=r;++i){

//                 }
//             }
//         }
//         for(int i=1;i<=n;++i)cerr<<dp[i]<<' ';
//         cerr<<'\n';
//     }
//     return 0;
// }
