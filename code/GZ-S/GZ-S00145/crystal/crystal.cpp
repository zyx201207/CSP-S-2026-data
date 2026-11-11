//GZ-S00145 周小晰 贵阳一中 
#include<bits/stdc++.h>
using namespace std;
long long a[100005],s[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool f=true;
	cin>>a[1]>>a[2];
	long long d = a[2]-a[1];
	for(int i = 3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=d) f=false;
	}
	if(f){
		long long ans = 0;
		for(int i = 1;m>=0;i++){
			m-=(i*d);
			ans++;
		}
		cout << ans;
	}else{
		int ans = 0;
		sort(a+1,a+1+n);
		for(int i = 1;i<=n;i++){
			int res=0;
			memset(s,0,sizeof s);
			for(int j = 1;j<=n;j++){
				s[j]=abs(a[i]-a[j]);
			}
			sort(s+1,s+n+1);
			int m1 = m;
			for(int j = 1;j<=n;j++){
				if(m1-s[j]>=0){
					m1-=s[j];
					res++;
				}
			}
			ans=max(ans,res);
		}
		cout << ans;
	}
	return 0;
}
//暴力+特解75Pts
//22min 15pts完成 
//36min 30pts
//1h 暴力搞定 开T2 
