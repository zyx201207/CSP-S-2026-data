#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],m,sum[N];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=1;
	for(int i=2;i<=n;i++){
		if(a[i]*(r-l+1)-(a[r]*(r-l+1))<=m){
			m-=(a[i]*(r-l+1)-(a[r]*(r-l+1)));
			r++;
		}else{
			m+=a[r]-a[l];
			m-=a[i]*(r-l)-a[r]*(r-l);
			l++;
			r++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<r-l+1<<"\n";
	return 0;
}
