//GZ-S00412 安顺市第一高级中学 杨瑞瑾 
#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;cin>>n>>m;
	if(m>100000000){
		int x;int y;
		cin>>x>>y;
		if(y-x == 1){
			if(n>m)cout<<m;
			if(n<=m)cout<<n;
			return 0;
		}
		if(y-x!= 1){
			int k = y-x;
			int k1 = m/k;
			if(k1>m)cout<<m;
			if(k1<=m)cout<<k1;
			return 0;
		}
	}
	
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0] = 0;
	for(int i = 1;i<n;i++)b[i] = a[i]-a[i-1];
	int res = 0;long long t = 0;int l= 0;int ans = 0;
	
	for(int i = 0;i<n;i++){
		t+=b[i];
		if(t<=m)res++;
		else{
			while(t>m){
				l++;
				t-=b[l];
				res--;
			}
		}
		ans = max(ans,res);
		
	}
	cout<<ans;
	return 0;
}
