#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long i=1,f=0;
    while(m>0&&i<n){
        for(int j=0;j<i;j++){
            if(m-(a[i]-a[j])>=0){
                m-=(a[i]-a[j]);
                a[j]=a[i];
            }else{
                f=1;
                break;
            }
        }
        i++;
        if(f==1){
            break;
        }
    }
    unsigned long long cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }else{
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    cout<<ans;
    return 0;
}
