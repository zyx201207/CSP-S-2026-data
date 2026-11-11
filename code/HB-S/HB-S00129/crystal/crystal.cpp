#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll n,m,a[N],b[N];
void solve1(){
	int cnt=0;
	if(a[2]==a[1]){
		cout<<n;
		return;
	}
	for(int i=1;i<n;i++){
		cnt+=a[i+1]-a[1];
		cout<<cnt<<endl;
		if(cnt==m){
			cout<<i+1;
			return;
		}
		if(cnt>m){
			cout<<i;
			return;
		}
		if(cnt<m&&i==n-1){
			cout<<n;
			return;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=1;
	}
	if(!flag){
		solve1();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		b[i]=a[i]-a[1];
	ll sum=0,cnt=0,ans=-1;
	for(int i=1;i<=n;i++){
		sum=cnt=0;
		for(int j=i;j>0;j--){
			cnt++;
			sum+=(b[i]-b[j]);
			if(sum>m){
				ans=max(ans,cnt-1);
				break;
			}
			if(sum==m){
				ans=max(ans,cnt);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
7 -3 -1 2 2
*/
