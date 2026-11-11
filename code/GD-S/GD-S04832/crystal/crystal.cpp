#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+5;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=16&&m<=2000){
		sort(a,a+n,cmp);
		long long ans=0;
		for(int i=0;i<n;i++){
			long long y=m,cnt=0;
			for(int j=0;j<n;j++){
				if(a[i]<a[j]) continue;
				long long x=a[i]-a[j];
				y=y-x;
				if(y<=0) break;
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans+1;
		return 0;
	}
	cout<<m+1;
	return 0;
}
 
