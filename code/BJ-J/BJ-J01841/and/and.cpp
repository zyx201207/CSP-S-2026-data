#include<bits/stdc++.h>
using namespace std;
int n,a[100005],maxx=0,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=2<<n;i++){
            int o=i,tot=0,cnt=0,is=0;
            for(int i=1;i<=n;i++){
                if(o%2==1){
                    cnt++;
                    if(is==0){
                        tot+=a[i];
                        is=1;
                    }
                    else{
                        tot&=a[i];
                    }
                }
                o=o>>1;
            }
            if(cnt==m)maxx=max(tot,maxx);
        }
        cout<<maxx<<endl;
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            int anss=a[i];
            for(int j=2;j<=n;j++){
                if(i==j){
                    continue;
                }
                maxx=max(maxx,anss&a[j]);
            }
        }
    }
    else if(m==n){
        maxx=a[1];
        for(int i=2;i<=n;i++){
            maxx&=a[i];
        }
    }
    cout<<maxx;
    return 0;
}
