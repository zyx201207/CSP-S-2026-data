#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int cnt[M];
bool f[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    stack <int> q;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        if(f[x]){
            int a;
            while(1){
                a=q.top();
                if(a!=x){
                    f[a]=0;
                    q.pop();
                }
                else{
                    break;
                }
            }
            q.pop();
        }
        q.push(x);
        f[x]=1;
        for(int j=1;j<=m;j++){
            if(f[j]){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

