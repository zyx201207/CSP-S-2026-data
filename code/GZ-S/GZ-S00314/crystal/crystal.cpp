//GZ-S00314 贵阳市第三实验中学 王钦澄 
#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin >> n >> m;
	a=vector<long long> (n+5);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.begin()+n);
	for(int i=n-1;i>=0;i--){
		long long b=m,c=0;
		cout << 1;
		for(int j=i;j>=0;j--){
			if(b<a[i]-a[j]) break;
			c++;
			b-=(a[i]-a[i]);
		}
		ans=max(ans,c);
		if(c>=i+1){
			break;
		} 
	}
	cout << ans;
	return 0;
}
