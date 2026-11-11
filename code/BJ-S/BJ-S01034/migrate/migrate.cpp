#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000010],n,d,min_len,ans;
vector<int> v[2000010];
int bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,0));
    while(!q.empty()){
        int sum=q.front().first,len=q.front().second;
        q.pop();
        for(int i=0;i<v[sum].size();i++){
            if(v[sum][i]==b)return len+1;
            q.push(make_pair(v[sum][i],len+1));
        }
    }
}
int dfs(int a,int b,int len){
    if(a==b){
        if(len==min_len)return 1;
        else return 0;
    }
    int sum=0;
    for(int i=0;i<v[a].size();i++){
        sum+=dfs(v[a][i],b,len+1);
    }
    return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n<=9){
            vector<int> v1[2000010];
            swap(v,v1);
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(x[i]-x[j])<=d){
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j)continue;
                    if(abs(x[i]-x[j])<=d)continue;
                    min_len=bfs(i,j);
                    if(dfs(i,j,0)==2)ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
