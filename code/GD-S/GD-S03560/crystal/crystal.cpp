#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,m,a[N],ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=0;
	while(r<n){
		r++;
		cnt+=(a[r]-a[r-1])*(r-1-l+1);
	//	if(r==1)cout<<cnt;
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
