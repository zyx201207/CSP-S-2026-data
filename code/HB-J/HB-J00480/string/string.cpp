#include<bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];
long long tong[30],maxn,maxb,sum;
int n;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        int t=c[i]-'a'+1;
        sum+=a[i];
        tong[t]+=a[i];
        if(maxn<tong[t]){
            maxn=tong[t];
            //maxb=t;
        }
    }

    cout<<sum-maxn;

    return 0;
}
