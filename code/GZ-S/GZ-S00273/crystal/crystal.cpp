//GZ-S00273 张轩哲 贵阳市第三中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10; 
int n,m,a[N],b[N],cnt,f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=f+1;j<i;j++){
			ans+=a[i]-a[j];
		}
		if(ans>m&&a[i+1]!=a[i]){		
			cnt=max(cnt,i-f-1);
			f=i;
		}
	}
	if(cnt==0){
		cout<<n;
		return 0;
	}
	cout<<cnt;
	
	return 0;
}
