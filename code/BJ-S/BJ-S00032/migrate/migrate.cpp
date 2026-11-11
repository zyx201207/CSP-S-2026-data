#include<bits/stdc++.h>
using namespace std;
struct ul{
    long long u,l;
    bool operator>(const ul other) const{
        return u>other.u;
    }
};
int c,t,n,d;
long long x[2000006], ans[2000006],minl[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // ctnd
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long finalans=0;
        for(int i=1;i<=n;i++){
            memset(ans,0,sizeof(ans));
            memset(minl,0x3f,sizeof(minl));
            ans[i]=1;
            priority_queue<ul,vector<ul>,greater<ul>> q;
            q.push({i,0});
            while(!q.empty()){
                ul s=q.top();
                q.pop();
                minl[s.u]=min(minl[s.u],s.l);
                for(int j=s.u+1;j<=n && x[j]-x[s.u]<=d;j++){
                    if(s.l+1==minl[j])
                        ans[j]+=ans[s.u];
                    else if(s.l+1<minl[j]){
                        ans[j]=ans[s.u];
                        minl[j]=s.l+1;
                    }
                    else{
                        continue;
                    }
                    q.push({j,s.l+1});
                }
            }
            for(int j=i+1;j<=n;j++){
                if(ans[j]==2)finalans++;
            }
        }
        cout<<finalans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
