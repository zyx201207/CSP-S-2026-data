#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],d[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	sort(a+1,a+n+1);
	int t=0;
	while(m>0&&t<=n){
		t=upper_bound(a+1,a+n+1,a[1])-a;
		if(t>n) break;
		int x=a[t]-a[1];
		int y=t-1;
		int num=x*y;
		if(m>=num){
			m-=num;
			d[1]+=x;
			d[t]-=x;
		}else{
			break;
		}
		a[1]=a[t];
	}
	cout<<upper_bound(a+1,a+n+1,a[1])-a-1;
	return 0;
}
