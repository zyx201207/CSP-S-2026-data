#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500050],b[500050],ans=0,nans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];

    }//315275
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    //for(int i=1;i<=n;i++){
    //    cout << b[i] << ' ';
    //}
    //cout << '\n';
    for(int r=1,l=0;r<=n;r++){
        //cout << "start:" << l <<' ' << r  <<"---" << b[r]-b[l]+m << ' ' <<a[r]*(r-l)<< '\n';
        if(b[r]-b[l]+m>=a[r]*(r-l)){
            //cout << l <<' ' << r  <<"---" << b[r]-b[l]+m << ' ' <<a[r]*(r-l)<< '\n';
            nans++;
            if(nans>ans){
                ans=nans;
            }
        }else{
            for( ;l<r;l++,nans--){
                if(b[r]-b[l]+m>=a[r]*(r-l)){
                    nans++;
                    //cout << l <<' ' << r  <<"---" << b[r]-b[l]+m << ' ' <<a[r]*(r-l)<< '\n';
                    if(nans>ans){
                        ans=nans;
                    }
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
