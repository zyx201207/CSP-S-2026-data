#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int a[MAXN];
char c[MAXN];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int mid=(n+1)/2;
    if(n%2==0){
        ll cnt=0;
        for(int i=1;i<=mid;i++){
            if(c[i]!=c[2*mid-i+1]){
                if(a[i]<=a[2*mid-i+1]){
                    cnt+=a[i];
                }
                else{
                    int u=a[i];
                    int tnt=2*mid-i+1;
                    while(u>0){
                        if(a[tnt]<u){
                            cnt+=a[tnt];
                            u-=a[tnt];
                        }
                        else{
                            cnt+=u;
                            break;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
        return 0;
    }
    else{
        ll ans=0;
        for(int i=1;i<=mid;i++){
            if(c[i]!=c[2*mid-i]){
                if(a[i]<=a[2*mid-i]){
                    ans+=a[i];
                }
                else{
                    if(c[i]!=c[2*mid-i-1]){
                        ans+=a[i];
                    }
                    else{
                        ans+=a[2*mid-i];
                    }
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
