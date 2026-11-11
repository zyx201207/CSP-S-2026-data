#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
int n;
ll a[200005],m;
ll ans=-0x3f3f3f3f3f3f3f3f;
bool v[200005];
void dfs(int x,int c){
    if(c==m){
        ll k=0;
        bool al=0;
        for(int i=1;i<=n;i++){
            if(v[i]){
                if(!al){
                    k=a[i];
                    al=1;
                }else k=(k&a[i]);
                //cout<<i<<' ';
            }
        }
        //cout<<endl;
        ans=max(ans,k);
        //cout<<ans<<endl;
        return ;
    }
    if(x==n+1){
        return ;
    }
    v[x]=1;
    dfs(x+1,c+1);
    v[x]=0;
    dfs(x+1,c);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll mx=-0x3f3f3f3f3f3f3f3f;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1||a[i]==3){
            cnt++;
        }
        mx=max(mx,a[i]);
    }
    if(n<=20){
        dfs(1,0);
        cout<<ans;
        //cout<<"a";
    }else if(m==1){
        cout<<mx;
        //cout<<"b";
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
        //cout<<"c";
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        //cout<<"d";
    }else if(mx<4){
        if(m<2||cnt<2||n<2||cnt-cnt%2+n-cnt<m){
            cout<<0;
            return 0;
        }else{
            cout<1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
