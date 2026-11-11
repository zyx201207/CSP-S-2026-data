#include<bits/stdc++.h>
using namespace std;
const int nnn=5*1e5+5;
#define int long long
int n,m;
int te=0;
int a[nnn];
int b[nnn];
int cnt=1;
int mx=INT_MIN;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int x=m;
    int p=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i]==0)sum++;
    }
    ////////////////////////////
    if(sum==n){
        cout<<n;
        return 0;
    }
    /////////////////////////////
    if(m==0){
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1])cnt++;
            else {mx=max(mx,cnt);cnt=1;}
        }
        cout<<mx;
        return 0;
    }
    ////////////////////////////
    for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
            cout<<a[j]<<' ';
        }
        cout<<'\n'<<m<<' '<<p<<' '<<cnt<<' '<<mx<<'\n';
        if(!p){
            i++;
            p=1;
        }else if(a[i]>a[i-1]){
            if(m>=a[i]-a[i-1]){
                m-=a[i]-a[i-1];
                a[i-1]+=a[i]-a[i-1];
                cnt++;
            }else{
                p=0;
                mx=max(mx,cnt);
                cnt=1;
                m=x;
                for(int j=i;j<=n;j++){
                    a[j]=b[j];
                }
            }

        }
        else if(a[i]<a[i-1]){
            if(m>=a[i-1]-a[i]){
                m-=a[i-1]-a[i];
                a[i]+=a[i-1]-a[i];
                cnt++;
            }else{
                p=0;
                mx=max(mx,cnt);
                cnt=1;
                m=x;
                for(int j=i;j<=n;j++){
                    a[j]=b[j];
                }
            }
        }else cnt++;
        if(m<=0&&a[i]!=a[i-1]){
            p=0;
            mx=max(mx,cnt);
            cnt=1;
            m=x;
            for(int j=i;j<=n;j++){
                a[j]=b[j];
            }
        }
    }
    cout<<mx;
    return 0;
}
