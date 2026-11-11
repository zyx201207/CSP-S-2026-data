#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],b[500005],l,ans,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //a[i]=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(l<=m){
            l+=(b[i]*(cnt+1));
            cnt++;
            if(ans<cnt)ans=cnt;
        }else{
            l=0;
            cnt=0;
        }
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
