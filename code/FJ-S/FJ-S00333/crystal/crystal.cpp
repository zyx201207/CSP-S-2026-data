#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a,a+n);
	int nx,e=1,mx=0,ans=1;
	long long p;
	mx=a[2]-a[1];
	for(int i=3;i<=n;i++){
		nx=(a[i]-a[i-1])*(i-e)+mx;
		if(nx<=m){
			ans=i+1-e;
			mx=nx;
			continue;
		}
		if(nx-a[e]>mx){
			break;
		}
		mx=nx-a[e];
		e++;
	}
	cout << ans;
	return 0;
}
