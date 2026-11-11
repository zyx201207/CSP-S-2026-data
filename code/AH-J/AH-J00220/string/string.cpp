#include<bits/stdc++.h>
using namespace std;
long long n,x[110000],ans,cnt,z;
char y[110000];
struct sp{
    long long g;
    char s;
}a[10101000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }else if(n==2){
        cin>>a[1].g>>a[1].s;
        cin>>a[2].g>>a[2].s;
        if(a[1].s==a[2].s){
            cout<<0;
        }else{
            cout<<min(a[1].g,a[2].g);
        }
        return 0;
    }
    ans=1;
    cin>>x[1]>>y[1];
    long long sl=x[1];
    z=x[1];
    for(int i=2;i<=n+1;i++){
        if(i<=n)cin>>x[i]>>y[i];
        if(y[i]==y[i-1]){
            sl+=x[i];
        }else{
            a[ans].g=sl;
            a[ans].s=y[i-1];
            ans++;
            sl=x[i];
        }
        z+=x[i];
    }
    if(ans==2){
        cout<<0;
        return 0;
    }else if(ans==3){
        if(a[1].s==a[2].s){
            cout<<0;
        }else{
            cout<<min(a[1].g,a[2].g);
        }
        return 0;
    }
    for(int i=1;i<=ans;i++){
        if(a[i].s==a[ans-i].s){
            cnt+=min(a[i].g,a[i-ans+1].g);
        }
    }
    cout<<(z-cnt)/2;
    return 0;
}
