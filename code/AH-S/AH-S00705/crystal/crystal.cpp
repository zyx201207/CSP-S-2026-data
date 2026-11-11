#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=5e5+10;//shui ti (zhuang bi) OvO
ll n,m,b[MAXN]={},a[MAXN]={},ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		a[i]=b[i]-b[i-1];
	}
	for(int i=2,j=0,last=1;i<=n;i++){
		j+=(i-last)*a[i];
		while(j>m && i>last){
			j-=(b[i]-b[last]);
			last++;
		}
		ll len=i-last+1;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
