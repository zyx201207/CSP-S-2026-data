#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
long long n,m,a[N],ans=1,s,mi=LONG_LONG_MAX,ma=LONG_LONG_MIN,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=mi+1;i<=ma;i++){
		s=0;
		sum=0;
		for(int j=n;j>=1;j--){
			if(a[j]<=i){
				sum+=(i-a[j]);
				if(sum>m) break;
				s++;
			}
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
