//GZ-J00011 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5;
ll n,m,a[N],mx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) mx=max(a[i]&a[i+1],mx);
	cout<<mx;
    return 0;
}
