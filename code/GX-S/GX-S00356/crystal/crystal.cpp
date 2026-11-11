#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],ang[500005],num[500005],u[500005],maxi=-1;
bool cmp(ll a,ll b){
    return a<b;
}
int lim(ll a[],int n){
    if(n%2==0){
        return (a[n/2]+a[n/2+1])/2;
    }
    else return a[(n+1)/2];
}
int findmax(ll ang[],ll m,ll n,ll i,ll k,ll f,ll g,ll u){
    if(i==n+1){
        //cout << "over:" << "k=" << k << endl;
        return k;
    }
    else{
        if((u+ang[i])<=m){
            u+=ang[i];
            //cout <<"u="<<u << endl;
            if(u<m){
                k=max(k,g);
                //cout << "not enough:k=" << k << endl;
                return findmax(ang,m,n,i+1,k,f,g+1,u);
            }
            else if(u==m){
                k=max(k,g);
                //cout << "same:" << "k=" << k << endl;
                return findmax(ang,m,n,i+1,k,f,g+1,u);
            }
        }
        else{
            //cout << "big:mine" << ang[f] << endl;
            u-=ang[f];
            return findmax(ang,m,n,i,k,f+1,g-1,u);
        }
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    num[0]=0;
    ll n,m,k=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    ll mid=lim(a,n);
    //cout << endl << "mid=" << mid << endl;
    for(int i=1;i<=n;i++){
        ang[i]=abs(a[i]-mid);
        //num[i]=num[i-1]+a[i];
    }
    //for(int i=1;i<=n;i++) cout <<ang[i] <<" ";
    ll ans=findmax(ang,m,n,1,0,1,1,0);
    cout << ans;
    return 0;
}
