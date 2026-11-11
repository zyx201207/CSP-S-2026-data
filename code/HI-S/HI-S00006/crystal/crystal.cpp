#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1,r=1;
	long long cnt=0;
	while(true){
		if(r>n){
			break;
		}
		cnt+=(a[r]-a[r-1])*(long long)(r-l);
//		cout<<l<<" "<<r<<" "<<cnt<<'\n';
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
