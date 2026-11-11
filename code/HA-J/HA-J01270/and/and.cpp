#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=2*1e5;
ll n,m;
ll a[N];
ll maxx=-1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ll num=a[i];	
		for(int j=1;j<m;j++){
			num=num&a[i+j];
		}
		maxx=max(maxx,num);
	}
	cout<<maxx;
	return 0;
} 
