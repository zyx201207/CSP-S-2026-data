#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1e6+5;

typedef long long LL;

LL a[N],m,d[N];
LL ses[N];
LL n;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    cin>>n>>m;

    for(LL i=1;i<=n;i++){

        cin>>a[i];
    }
    sort(a+1,a+1+n);

    for(LL i=2;i<=n;i++){
        d[i]=abs(a[i]-a[i-1]);
    }


    LL now=0,before=0;
    LL ans=0,mas=0;
    for(int i=1;i<=n;i++){
        if(abs(d[i])>m){
            continue;
            ans=0;
        }
        ses[i]=ses[i-1]+(d[i]*(i-1));
        if(ses[i]<=m){
            ans++;
            mas=max(mas,ans);
        }
    }
    cout<<mas<<endl;


    return 0;
}

