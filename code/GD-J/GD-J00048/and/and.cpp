#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll a[200005],ans,num;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=n;i++){
		if(num<=m){ans=(ans&a[i]);num++;}
	}
	cout<<(ans);
    return 0;
}
