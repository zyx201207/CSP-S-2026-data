#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,ans,maxn=INT_MIN;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	bool o=true;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	long long k=a[2]-a[1];
	long long c=m;
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]!=k){
			o=false;
			break;
		}
	}
	if(o==false){
		for(int i=2;i<=n;i++){
			ans=0;
			m=c;
			for(int j=i;j>=1;j--){
				if(m-a[i]+a[j]<0){
					break;
				}
				else{
					m-=a[i]-a[j];
					ans++;
				}
				maxn=max(maxn,ans);
		}
		}
		cout << maxn;
	}
	else{
	while(m>ans*k){
		m-=ans*k;
		ans++;
	}
	cout << ans;
}
	return 0;
} 
