//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+5;
//int n,cnt;
//vector<pair<int,int>> g[maxn];
//stack<int> st;
//bool vis[maxn];
//void dfs(int start){
//    st.push(start);
//    vis[start]=true;
//    while(!st.empty()){
//        int xb=st.top();
//        st.pop();
//        for(auto pr:g[xb]){
//            if(vis[pr.first]) continue;
//            vis[pr.first]=true;
//            st.push(pr.first);
//        }
//    }
//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        int u,v,w;
//        cin>>u>>v>>w;
//        g[u].push_back({v,w});
//        g[v].push_back({u,w});
//    }
//    for(int i=1;i<=n;i++){
//        if(!vis[i]){
//            dfs(i);
//            cnt++;
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,cnt;
vector<int> g[maxn];
queue<int> q;
bool vis[maxn];
void bfs(int start){
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int xb=q.front();
        q.pop();
        for(auto pr:g[xb]){
            if(vis[pr]) continue;
            vis[xb]=true;
            q.push(xb);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
            cnt++;
        }
        while(!q.empty()) q.pop();
    }
    cout<<cnt<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],fi;
int main(){
    cin>>n>>fi;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    while(l<=r&&r<=n){
        int mid=(l+r)/2;
        if(fi<a[mid]) r=mid-1;
        else if(fi>a[mid]) l=mid+1;
        else{
            cout<<mid<<endl;
            break;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],t[maxn],ans;
void fz(int l,int r){
    int mid=(l+r)/2;
    fz(l,mid);
    fz(mid+1,r);
    int i=l,j=mid+1,k=1;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            t[k++]=a[i++];
        }
        else{
            t[k++]=a[j++];
            ans+=mid-l+1;
        }
    }
    while(i<=mid) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=t[i];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    fz(1,n);
    cout<<ans<<endl;
    return 0;
}
