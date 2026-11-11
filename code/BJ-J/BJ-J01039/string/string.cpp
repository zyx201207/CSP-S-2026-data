#include <bits/stdc++.h>
using namespace std;
long long n,L,a[200005],js,ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    int j=n-1;
    for(int i=0;i<n;i++){
        //cout<<ans<<' ';
        if(i==j){
            if(js){
                ans+=js;
                //cout<<ans<<' ';
                if(i>0&&a[j]==a[i-1]){
                    ans-=js;
                }
                //cout<<ans<<' ';
            }
            break;
        }
        js+=a[i];
        //cout<<js<<endl;
        for(;js-a[j]>0;j--){
            js-=a[j];
            if(c[i]!=c[j]){
                ans+=a[j];
                //cout<<'j'<<j<<' '<<a[j]<<endl;
            }
            //cout<<js<<endl;
        }
    }
    cout<<ans;
    return 0;
}
