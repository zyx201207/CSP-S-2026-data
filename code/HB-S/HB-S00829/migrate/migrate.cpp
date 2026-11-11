#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,x[N],sum,dis,cnt,ans;
void workA(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sum=x[2]-x[1];
    //cout<<sum<<" "<<n<<" "<<d<<"\n";
    if(sum>d)cout<<"0\n";
    else if(sum==0)cout<<"0\n";
    else if(2*d/sum>n)cout<<"0\n";
    else if(sum==d)cout<<"0\n";
    else cout<<n-(2*(d/sum)-1)<<"\n";
}
void dfs(int z,int y,int s){
    if(z==y){
        if(s<dis){
            cnt=0;
            dis=s;
        }
        if(s==dis)cnt++;
        return;
    }
    for(int i=z+1;i<=y;i++){
        if(x[i]-x[z]<=d){
            dfs(i,y,s+1);
        }
        else return;
    }
}
void work(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dis=0x3f,cnt=0;
            dfs(i,j,0);
            if(cnt==2)ans++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(c==11||c==12){
            workA();
        }
        else work();
    }
    return 0;
}
