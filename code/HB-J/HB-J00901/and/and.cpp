#include<bits/stdc++.h>
using namespace std;
int pw[35],a[200005][35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    queue<int> q1,q2,q3;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int tmp=x;
        int p=0;
        while(tmp){
            if(tmp%2) a[i][p]=1;
            tmp/=2;
            p++;
        }
        q1.push(i);
    }
    pw[0]=1;
    for(int i=1;i<=31;i++){
        pw[i]=2*pw[i-1];
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        while(q1.size()){
            int now=q1.front();
            q1.pop();
            if(a[now][i]){
                q2.push(now);
            }
            else{
                q3.push(now);
            }
        }
        if(q2.size()>=m){
            ans+=pw[i];
            while(q2.size()){
                q1.push(q2.front());
                q2.pop();
            }
            while(q3.size()){
                q3.pop();
            }
        }
        else{
            while(q2.size()){
                q1.push(q2.front());
                q2.pop();
            }
            while(q3.size()){
                q1.push(q3.front());
                q3.pop();
            }
        }
    }
    cout<<ans;
    return 0;
}
