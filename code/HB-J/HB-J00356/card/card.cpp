#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],k;
queue <int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    k=n-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        int f[N]={0};
        q.push(a[n-k]);
        for(int i=n-k+1;i<=n;i++){
            if(q.front()==a[i]){
                while(!q.empty()) q.pop();
                q.push(a[i]);
            }else q.push(a[i]);
        }
        while(!q.empty()){
            if(s[q.front()]<l) s[q.front()]++;
            q.pop();
        }
        k--;
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
}
