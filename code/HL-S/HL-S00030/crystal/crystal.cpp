#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[1000000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=1,ans1;
    int f=0;
    for(int i=1;i<=n;i++){
        long long s=m;
        if(m!=0 && a[i+1]>a[i] && a[i+1]-a[i]<=m){
            ans=1;
            for(int j=i;j>0;j--){
                s-=a[i+1]-a[j];
                if(s>=0){
                    ans++;
                    f=1;
                }else{
                    break;
                }
            }
        }else if(a[i+1]==a[i]){
            ans++;
            f=1;
        }
        ans1=max(ans,ans1);
    }
    if(f){
        cout<<ans1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
