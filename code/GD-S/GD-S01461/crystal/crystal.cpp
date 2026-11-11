#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+1000;
ll m,sum[N],a[N];
int mx=1;
int n;
ll sm(int l,int r){
	return sum[r]-sum[l-1];
}
bool ck(int i,int j){
	int k=i-j;
	if(1ll*k*a[i]-sm(j,i-1)<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int r=i-1,l=1,ans=1000000;
		while(l<=r){
			int md=(l+r)/2;
			if(ck(i,md)){
				ans=md;
				r=md-1;
			}else l=md+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
}
