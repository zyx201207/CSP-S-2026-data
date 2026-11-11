#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int a[500005],s[500005];
int k[500005],d[500005],q[500005];
bool cmp(int p,int w){
	return p<w;
	}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	f(i,1,n){
		cin >> a[i];
	}
	int qer=a[1];
	bool flag=false;
	f(i,1,n){
		if(qer!=a[i]){
			flag=true;
			break;
		}
	}
	if (!flag){
		cout << n;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int pian=0;
	f(i,2,n){
		s[i]=a[i]-a[i-1];
		//cout << s[i] << ' ';
		//k[i]=s[i];
	}
	for(int i=n-1;i>=1;i--){
		q[i]=a[i]-a[i+1];
	}
	for(int i=n-1;i>=1;i--){
		k[i]=(i+1)*q[i]+k[i+1];
}
	f(i,2,n){
		d[i]=(i-1)*s[i]+d[i-1];
		//cout << d[i] << ' ' ;
	}
	int ans=0;
	f(i,1,n){
		//cout << k[i] << ' ' << d[i] << '\n';
		if (d[i]>m){
			ans=i-1; break;
	}
	}
	if (ans==0){
		cout << n;
}
	cout << ans;
	//cout << trueans+2+pian;
	return 0;
}
