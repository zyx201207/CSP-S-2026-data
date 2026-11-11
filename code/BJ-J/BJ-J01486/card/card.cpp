#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
bool f[maxn];
int a[maxn];
int cnt[maxn];
int n,m;
stack<int> st;
void solve1(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                while(st.top()!=a[j]){
                    f[st.top()]=0;
                    st.pop();
                }
                st.pop();
            }
            f[a[j]]=1;
            st.push(a[j]);
        }
        for(int j=1;j<=m;j++){
            cout<<f[j]<<' ';
            cnt[j]+=f[j];
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]){
            cout<<i<<' ';
        }
    }
    /*
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    */
    cout<<endl;
    return 0;
}
//26.10.31.11.30,Treak||Treat!?
//AFO in 2026?
//...C2029 of hpg...
/*
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("tmp.in","r",stdin);
    freopen("tmp.out","w",stdout);
    return 0;
}
*/
