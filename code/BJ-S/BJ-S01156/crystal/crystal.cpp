#include <bits/stdc++.h>
using namespace std;
int n;
int a[500010];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int ans=INT_MIN;
    bool flagab=true;
    int d=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            d=a[2]-a[1];
        }
        if(i>2){
            if(a[i]-a[i-1]!=d){
                flagab=false;
            }
        }
    }
    d=abs(d);
    if(flagab){
        int x=((d+sqrt(8*d*m+d*d))*1.0/(2*d));
        cout<<x<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int cnt=0,tmp=1;
        for(int j=i-1;j>=1;j--){

            int ppp=cnt+abs(a[i]-a[j]);
            if(ppp>m){
                ans=max(ans,tmp);
                break;
            }else{
                tmp++;
                cnt=ppp;
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}
