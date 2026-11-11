#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200010],b[200010],tmp=0,t,sum=0,ans=0;
    char c[200010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        a[i]=tmp+1;
        b[i]=tmp+t;
        tmp+=t;
        cin>>c[i];
        sum+=t;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>sum/2){
            break;
        }
        for(long long j=a[i];j<=min(b[i],sum/2);j++){
            for(int k=1;k<=n;k++){
                if(b[k]>=(sum-j+1)){
                    if(c[k]!=c[i]){
                        ans++;
                    }
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
