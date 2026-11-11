//GZ-S00115 遵义市红花岗区老城小学 雷丰硕
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s,ans[500005],tj1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
			tj1=0;
		}
	}
	if(tj1==1){
		for(long long i=1;i<=n;i++){
			ans[i]=a[n]-a[i];
		}
		long long x=m;
		sort(ans+1,ans+n+1);
		for(long long i=1;i<=n;i++){
			if(x<ans[i]){
				break;
			}
			x-=ans[i];
			s++;
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			ans[j]=a[i]-a[j];
		}
		long long x=m,s1=0;
		sort(ans+1,ans+i+1);
		for(long long j=1;j<=i;j++){
			if(x<ans[j]){
				break;
			}
			x-=ans[j];
			s1++;
		}
		if(s1<=s){
			break;
		}
		s=max(s1,s);
		
	}
	cout<<s;
	
	return 0;
}
//密码:Oct31==Dec25?
