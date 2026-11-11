#include<bits/stdc++.h>
using namespace std;
int C,T;
int n;
long long d;
long long a[2000005];
vector<int> ways[2000005];
void DFS(int x,int st){
    if(x==n) return;
    for(int i=x+1;i<=n;i++){
        if((a[i]-a[x])<=d){
            ways[i].push_back(st+1);
            DFS(i,st+1);
        }
        else break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        long long sum=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            for(int kk=1;kk<=n;kk++) ways[kk].clear();
            DFS(i,0);
            for(int kk=1;kk<=n;kk++){
                int minn=n+1;
                bool f=false,ff=true;
                for(auto j:ways[kk]){
                    if(minn>j) minn=j,f=false;
                    else{
                        if(f==true) ff=false;
                        f=true;
                        //cout<<"i:"<<i<<" minn:"<<j<<endl;
                    }
                }
                if(f==true && ff==true) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
