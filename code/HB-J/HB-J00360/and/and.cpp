# include <bits/stdc++.h>
using namespace std;
const int CLS=2e5+10;
int a[CLS],s[CLS][40],n,m,vis[CLS];
vector <int> v[50];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        vis[i]=132;
        int cnt=-1,t=a[i];
        while(t>0){
            cnt++;
            s[i][cnt]=t%2;
            //cout<<cnt<<"\n";
            if(t%2==1) v[cnt].push_back(i);
            t/=2;
        }
    }
    int cnt=n;
    for(int i=32; i>=0; i--){
        if(v[i].size()<m){
            for(int i=1; i<=n; i++) vis[i]--;
            continue;
        }
        int count=0,len=v[i].size();
        queue <int> f;
        for(int j=0; j<len; j++){
            if(vis[v[i][j]]==i+100) count++,f.push(v[i][j]);
        }
        if(count<m){
            for(int i=1; i<=n; i++) vis[i]--;
            continue;
        }
        cnt=0;
        while(!f.empty()){
            int t=f.front(); f.pop();
            vis[t]=100+i-1,cnt++;
        }
    }
    long long ans=LONG_MAX;
    for(int i=1; i<=n; i++){
        if(vis[i]==99) ans=min(ans,a[i]*1ll);
    }
    cout<<ans;
    return 0;
}
