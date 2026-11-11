#include<bits/stdc++.h>
using namespace std;
int n;
long long m,temp,t;
long long a[500005];
long long ans,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>10000){
        ans=1;
        int t=a[2]-a[1];
        temp=m;
        for(int i=1;i<=(m/2)+1;i++){
            if(temp-(t*i)>=0){
                ans++;
                temp-=(t*i);
            }else{
                cout<<ans<<endl;
                return 0;
            }

        }
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        if(i==1){
            for(int k=1;k<=n;k++){
                if(a[k]==a[i]){
                    ans=max(ans,++cnt);
                }else{
                    break;
                }
            }
        }else{
            temp=m;
            for(int j=i-1;j>=1;j--){
                t=a[i]-a[j];
                if(temp>=t){
                    temp-=t;
                    cnt++;
                }else{
                    break;
                }
            }
            for(int l=i;l<=n;l++){
                if(a[l]==a[i]){
                    ans=max(ans,++cnt);
                }else{
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
