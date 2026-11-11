#include<bits/stdc++.h>
using namespace std;
int n,ans=1,a[500005];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    long long i=0;
    for(int i=1;i<n;i++){
        if(m<=0){
            break;
        }
        else if(m<i*(a[i+1]-a[i])){
            m=0;
            break;
        }
        else{
            m-=(a[i+1]-a[i])*i;
            for(int j=1;j<=i;j++){
                a[j]=a[i+1];
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            ans++;
        }
        else{
            printf("%d",ans);
            return 0;
        }
    }
    printf("%d",ans);
    return 0;
}
