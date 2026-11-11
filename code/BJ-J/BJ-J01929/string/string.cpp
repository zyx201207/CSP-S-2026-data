#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int r=n+1,rp=0;//还剩几个
    for(int i=1;i<=n;i++){
            //cout<<i<<" :";
        if(i>=r) break;
        int x=a[i];
        char y=c[i];
        while(x>0){
         //   cout<<rp<<" "<<r<<" "<<ans<<"&&"<<endl;
            if(rp>x){
                rp-=x;
                if(y!=c[r]){
                    ans+=x;
                }
                break;
            }
            if(rp<=x&&rp!=0){
                x-=rp;
                if(y!=c[r]){
                    ans+=rp;
                }
                rp=0;
            }
            if(rp==0){
                r--;
                if(a[r]>x){
                    rp=a[r]-x;
                    if(y!=c[r]){
                        ans+=x;
                    }
                    break;

                }
                if(a[r]<=x){
                    x-=a[r];
                    if(y!=c[r]){
                        ans+=a[r];
                    }

                }
            }

        }
   //     cout<<"%"<<rp<<endl;

    }
    cout<<ans;
   return 0;
}

