#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int M=5e+5;
long long a[M];
int ans=0,cnt=0,minl=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            if(a[i]>minl){
                if(minl==0){
                    minl=a[i];
                }else if(minl>a[i]){
                    cnt=minl-a[i];
                    if(cnt<m){
                        ans++;
                        m-=j*cnt;
                    }
                }
            }else if(m==0){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
