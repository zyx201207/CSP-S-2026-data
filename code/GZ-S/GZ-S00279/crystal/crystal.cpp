//GZ-S00279 华东师范大学附属贵阳学校 刘凌舟 
#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long s=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s/=n;
	int k,idx;
	long long c=0x3f;
	for (int i=1;i<=n;i++){
		if (abs(a[i]-s)<=c) k=a[i],idx=i,c=abs(a[i]-s);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=idx;i>=1;i--){
		if (k-a[i]>m) break;
		else{
			m-=k-a[i];
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
