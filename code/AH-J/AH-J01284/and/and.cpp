#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int d,t=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d|=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(a[m]==0){
		cout<<0;
		return 0;
	}
	while(d){
		d>>=1;
		t++;
	}
	for(int i=t;i>=0;i--){//2^30 -> 2^0
		int sum=2147483647;//MAX_INT
		int now=1<<i;
		for(int j=1;j<=m;j++){
			sum&=a[j];
		}
		if((now&sum)==0){
			for(int j=1;j<=n;j++){
				a[j]&=(2147483647-now);
			}
		}
		sort(a+1,a+n+1,greater<int>());
	}
	int ans=2147483647;
	for(int i=1;i<=m;i++)
		ans&=a[i];
	cout<<ans; 
	return 0;
} 
