#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pi3 pair<int,pii>
int lowbit(int x){
    return x&-x;
}
ll c,t,n,m,a[2000001],maxrt[2000001],ans;
ll us[2000001];
pii mp[10001][10001];//[from][to] {min,num}
void init(int x){
    for (int i=x+1;i<=n;i++){
        mp[x][i]={-1,0};
    }
    return ;
}
void dfs(int x){
    init(us[x]);
    for (int i=maxrt[x];i>x;i--){
        mp[us[x]][i]={1,1};
        for (int j=n;j>maxrt[x];j--){
            ll load=mp[us[i]][j].first+1;
            if(mp[us[x]][j].first==-1 or mp[us[x]][j].first>=load){
                if(mp[us[x]][j].first==load){
                    mp[us[x]][j].second+=mp[us[i]][j].second;
                }
                else{
                    mp[us[x]][j].first=load;
                    mp[us[x]][j].second=mp[us[i]][j].second;
                }
            }
        }
    }
    for (int i=n;i>maxrt[x];i--){
        if(mp[us[x]][i].second==2) ans++;
    }
    return ;
}
int main(){
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        int num=1;
        stack<int> st;
        for (int i=1;i<=n;i++){
            st.push(n-i+1);
            cin>>a[i];
            while(a[i]>a[num]+m){
                maxrt[num]=i-1;
                num++;
            }
        }
        for (int i=num;i<=n;i++) maxrt[i]=n;
        if(a[n]-a[1]<=m){
            cout<<0<<endl;
            continue;
        }
        for (int i=n,j=n;i>=1;i--){
            while(j>maxrt[i]){
                st.push(us[j]);
                j--;
            }
            us[i]=st.top();
            st.pop();
        }
        init(n);
        for (int i=n-1;i>=1;i--){
            dfs(i);
        }
        cout<<ans<<endl;

    }
    
    return 0;
}