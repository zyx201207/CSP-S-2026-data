#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MX=30;
int n,k,cnt,ans;
int num[200005];
int num1[200005];
bool isuse[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    cnt=n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=MX;i>=0;i--){
        int ccnt=0;
        for(int j=1;j<=cnt;j++){
            isuse[j]=false;
            num1[j]=0;
        }
        for(int j=1;j<=cnt;j++){
            if(num[j] & (1<<i)){
                ccnt++;
                num1[ccnt]=num[j];
            }
        }
        if(ccnt>=k){
            ans+=(1<<i);
            cnt=ccnt;
            for(int j=1;j<=cnt;j++){
                num[j]=num1[j];
            }
        }
        //cout<<ccnt<<' '<<cnt<<'\n';
    }
    cout<<ans;
}
