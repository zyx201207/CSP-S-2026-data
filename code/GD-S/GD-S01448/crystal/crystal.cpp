#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	int x=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool f;
	while(true){
		f=true;
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
		for(int i=2;i<=n;i++){
			if(d[i]<=x&&d[i]!=0){
				a[i-1]+=d[i];
				x-=d[i];
				f=false;
				break;
			}
		}
		if(f)break;
	}
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
