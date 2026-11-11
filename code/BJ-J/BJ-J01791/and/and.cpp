#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],b[35],maxx=-1,sum=-1,ok2=0/*,ok1=0*/;
void dfs(ll p,ll num,ll ans){
    if(num==m&&ans>maxx)maxx=ans;
    if(p>n)return ;
    if(num==0){
        dfs(p+1,num+1,a[p]);
    }else{
        dfs(p+1,num+1,(ans&a[p]));
    }
    dfs(p+1,num,ans);
}
bool o(int x){
    int w=0,s=0;
    while(x){
        s+=x%2;
        w++;
        x/=2;
    }
    if(s==w){
        b[s]++;
        return true;
    }
    else return false;
}
int po(int x){
    int s=1;
    for(int j=1;j<=x;j++)s*=2;
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=sum)sum=a[i];
        if(!o(a[i])){
            ok2=1;
        }/*if(a[i]!=i-1){
            ok1=1;
        }*/
    }
    if(m==1){
        cout<<sum;
        return 0;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            ll ans=0;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(ans==0)ans=a[j];
                    else ans=(ans&a[j]);
                }
            }
            if(ans>maxx)maxx=ans;
        }
        cout<<maxx;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>=maxx)maxx=(a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }else if(ok2==0){
        for(int i=20;i>=0;i--){
            m-=b[i];
            if(m<=0){
                cout<<po(i)-1;
                return 0;
            }
        }
        /*for(int i=1;i<=20;i++){
            cout<<i<<" "<<b[i]<<endl;
        }*/
    }/*if(ok1==0){

    }*/
    dfs(1,0,0);
    cout<<maxx;
    return 0;
}
