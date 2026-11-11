#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bye return 0
#define hello ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define frein freopen("crystal.in","r",stdin)
#define freout freopen("crystal.out","w",stdout)

int main(){
	hello;
    frein;
    freout;

    ll n,m,cnt=0,b;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[1]<=a[2]){
            a[1]++;
            cnt++;
        }else{
            cnt--;
        }
        // if(cnt>m){
        //     cout<<m;
        //     bye;
        // }
    }
    cout<<abs(cnt);

	bye;
}
//我并不会做,0 pts,1h

//17:22 才发现需要排序

//HB竟然可以使用VS code 太强了

//有幸知道监考自己忘记自己设置的电脑密码
