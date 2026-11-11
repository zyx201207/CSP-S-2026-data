#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int a[N];
char b[N];
int n;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i];
        sum += a[i];
    }
    int l = 1,r = sum;
    int pl = 1,pr = n;
    int ll = a[1],lr = a[n];
    int ans = 0;
    while(l < r){
            //cout<<"l="<<l<<"r="<<r<<endl;
        if(b[pl] != b[pr]){
            ans += min(ll,lr);
            //cout<<"DEBUG:"<<l<<"<<"<<r<<"<<"<<ans<<"<<"<<ll<<"<<"<<lr<<endl;
            //bu xiang deng
            if(ll< lr){
                b[pl] = b[pr];
            }
            else{
                b[pr] = b[pl];
            }

        }
        //cout<<"DBG!!!!!!"<<endl;
        int k = min(ll,lr);
        l +=k;
        r -=k;
        ll -= k;
        lr -= k;

        //cout<<"LL"<<ll<<endl;
        if(ll == 0){
            //cout<<"dbgl";
            pl++;
            ll = a[pl];
        }
        if(lr == 0){
            //cout<<"dbgr";
            pr--;
            lr = a[pr];
        }


        //cout<<l<<","<<r<<","<<ll<<","<<lr<<endl;

    }
    cout<<ans;
    return 0;
}
