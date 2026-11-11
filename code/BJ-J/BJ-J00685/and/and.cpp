#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll m;
ll a[200010];
vector<int> b;
ll fg[50]={8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728};
bool tmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,tmp);

        for(int j=25;j>=1;j--){
            for(int i=1;i<=n;i++){
            if(a[i]==fg[j]-1||a[i]==fg[j]-2||a[i]==fg[j]-3||a[i]==fg[j]-4||a[i]==fg[j]-5||a[i]==fg[j]-6||a[i]==fg[j]-7||a[i]==fg[j]-8||a[i]==fg[j]-9||a[i]==fg[j]-10){
                if(a[i]!=0){
                    b.push_back(a[i]);
                }

                a[i]=0;

            }
        }
    }
    //cout<<m;
    ll sum=0;

    if(b.size()<m){
        sort(a+1,a+1+n,tmp);
        for(int i=1;i<=m;i++){
            b.push_back(a[i]);
        }
    }
    ll ans=2147483647;
for(auto v:b){
        ans&=v;
    }
cout<<ans;
    return 0;
}

