#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=-1e5-5;
int a[N];
int f[N];
int mx=1;
void check(int x){
	int tmp=m,now=1;
	mx=1;
	for(int i=n;i>=1;i--){
		f[i]=x-a[i];
		if(tmp>=f[i]&&f[i]>=0){
			tmp-=f[i];
			f[i]=0;
		}else if(tmp<f[i]&&f[i]>=0){
			f[i]-=tmp;
		}
	}
	for(int i=2;i<=n;i++){
		if(f[i]==f[i-1]){
			now++;
			mx=max(mx,now);
		}else now=1;
	}
	ans=max(ans,mx);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=a[2]-a[1];
	bool flag=0;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]+d){
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<signed(-1+sqrt(1+8*m/d))/2+1;
		return 0;
	}
	for(int i=a[1];i<=a[n];i++){
		check(i);
	}
	cout<<ans;
	return 0;
}
