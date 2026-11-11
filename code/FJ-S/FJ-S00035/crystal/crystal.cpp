//MUST USE LONG LONG,55 pts or more
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N=5e5+5;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	file("crystal");//不要注释，检查文件名
	long long ans=0,n,m,a[N]={0},s[5005][5005]={0},s2[5005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5005){
		for(long long j=1;j<=n;j++){
			for(long long i=j;i<=n;i++){
				if(i!=j) s[j][i]=s[j][i-1]+(i-j)*(a[i]-a[i-1]);
			}
		}
		for(long long j=1;j<=n;j++){
			bool flag=1;
			for(long long i=1;i<=n;i++){
				if(m<s[j][i]){
					flag=0;
					ans=max(i-j,ans);
					break;
				}
			}
			if(flag){
				ans=max(ans,n-j+1);
				break;
			}
		}
	}else{
		for(long long i=1;i<=n;i++){
			if(i!=1) s2[i]=s2[i-1]+(i-1)*(a[i]-a[i-1]);
		}
		bool flag=1;
		for(long long i=1;i<=n;i++){
			if(m<s2[i]){
				flag=0;
				ans=i-1;
				break;
			}
		}
		if(flag) ans=n;
	}
	cout<<min(n,ans);
	return 0;
}


