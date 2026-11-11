#include<iostream>
#include<algorithm>
using namespace std;
const int MXN=5e5+1;
long long int n,m;
long long a[MXN];
long long ans=0;
void solve(int d){
//	cout<<d<<":";
	long long tar=a[d],t=m,cnt=1;
	for(int i=d-1;i>=1;--i){
//		cout<<tar-a[i]<<" ";
		if(t>=(tar-a[i])){
			t-=(tar-a[i]);
			cnt++;
		}else break;
	}
//	cout<<"|"<<cnt<<endl;
	ans=max(ans,cnt);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		solve(i);
	}
	cout<<ans;
	return 0;
}
