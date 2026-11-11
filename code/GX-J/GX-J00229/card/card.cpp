#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N=5e5+10;

ll n,m,x,a[N],t[N],l=0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie (0);
    cout.tie(0);

    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);



    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        a[i]=x;

    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
