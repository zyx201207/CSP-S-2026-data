#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[1000005],a[1000005],ans,aaa[1000005],bbb[1000005];
queue<long long> q;
void dp(int z){
    queue<pair<int,int>>qq;
    qq.push({z,1});
    while(!qq.empty()){
        int abc=qq.front().first;
        for(int i=abc+1;i<=a[abc];i++){
            if(bbb[i]==0||bbb[i]==qq.front().second){
                aaa[i]++;
                bbb[i]=qq.front().second;
                qq.push({i,qq.front().second+1});
            }
        }
        qq.pop();
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    aaa[0]=1;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            while(!q.empty()){
                if(x[q.front()]+d<x[i]){
                    a[q.front()]=i-1;
                    q.pop();
                }else break;
            }
            q.push(i);
            if(i==n){
                while(!q.empty()){
                    a[q.front()]=n;
                    q.pop();
                }
            }
        }
        for(int i=1;i<=n;i++){
            dp(i);
            for(int j=1;j<=n;j++){
                if(aaa[j]==2)ans++;
                aaa[j]=0;
                bbb[j]=0;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
