#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int max_n=5e5+5;
int n,m,a[max_n];
int b[max_n],head,tall;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int ans=0,num=0;
	head=0;tall=1;
	for(int i=1;i<=n;i++){
		b[++head]=a[i];
		num+=b[tall]-a[i];
		while(num>m){
			tall++;
			num-=(b[tall-1]-b[tall])*(head-tall+1);
		}
		ans=max(ans,head-tall+1);
	}
	cout<<ans;
	return 0;
}
