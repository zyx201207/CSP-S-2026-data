#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mid=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		if(m==0)break;
		if(a[i]+m<mid)continue;
		else{
			int k=mid-a[i];
			a[i]+=k;
			m-=k;
		}
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])sum++;
	}
	cout<<sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
