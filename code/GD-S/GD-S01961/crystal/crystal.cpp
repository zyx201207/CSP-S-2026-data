#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long s=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m)break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
