#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d,x[2000001],ans;
int bfs(int s,int e){
    int cnt=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int sizee=q.size();
        while(sizee--){
            int p=q.front();
            q.pop();
            for(int i = p-1;i>=1;i--){
                if(abs(x[i]-x[p])<=d){
                    q.push(i);
                    if(i==e){
                        cnt++;
                    }
                }else{
                    break;
                }
            }
            for(int i = p+1;i<=n;i++){
                if(abs(x[i]-x[p])<=d){
                    q.push(i);
                    if(i==e){
                        cnt++;
                    }
                }else{
                    break;
                }
            }
        }
        if(cnt){
            return cnt;
        }
    }
}
int main(){
    freopen("migrate1.in","r",stdin);
    freopen("migrate1.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(bfs(i,j)==2){
                    ans++;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
