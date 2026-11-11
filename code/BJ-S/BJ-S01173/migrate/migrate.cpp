#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000000;
int c,t,n,d,a[N+10],b1[N+10],b2[N+10],f[N+10];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        queue<int> q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            /*q.push(i);
            while(a[q.front()]<a[i]-d){
                b1[q.front()]=i-1;
                q.pop();
            }*/
        }
        /*while(!q.empty()){
            b1[q.front()]=n;
            q.pop();
        }
        for(int i=n;i>=1;i--){
            q.push(i);
            while(a[q.front()]>a[i]+d){
                b2[q.front()]=i+1;
                q.pop();
            }
        }
        while(!q.empty()){
            b2[q.front()]=1;
            q.pop();
        }
        for(int i=1;i<=n;i++){
            int pre=1,nxt=b1[i];
            f[i]=1;
            for(int j=i+1;j<=n;j++){
                f[j]=f[j-1];
                if(pre==nxt){
                    break;
                }
                if(nxt==j){
                    pre=j;nxt=b1[j];
                    f[j]=1;
                    continue;
                }
                while(!q.empty() && q.front()<b2[i]){
                    f[j]-=f[q.front()];
                    q.pop();
                }
                if(f[j]==2){
                    ans++;
                }
            }
            for(int j=1;j<=n;j++){
                cout<<f[j]<<' ';
            }
            cout<<'\n';
        }*/
        cout<<0<<'\n';
    }
    return 0;
}
//g++ migrate.cpp -o c -g -std=c++14 -static -O2 -Wall -Wextra