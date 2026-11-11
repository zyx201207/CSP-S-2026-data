#include<bits/stdc++.h>
using namespace std;
int a[555555],b[555555];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0,flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int z=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=z){
            flag=0;
        }
    }
    if(flag==1){
        int m1=m/z,cnt=0;
        int y=0;
        while(m1-y>=0){
            m1-=y;
            cnt++;
            y++;
        }
        cout<<min(cnt,n);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            b[i]=a[i];
        }
        int k=m;
        for(int j=i;j>=1;j--){
            if(k>=b[i]-b[j]){
                k-=b[i]-b[j];
                b[j]=b[i];
            }else{
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(b[j]==b[i]){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
