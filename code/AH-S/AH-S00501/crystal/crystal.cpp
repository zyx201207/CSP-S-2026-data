#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n,m;
int check(int x){
	int ans=0,use=0;
	for(int i=x-1;i>=1;i--){
		int lf=abs(a[x]-a[i]);
		if(lf+use<=m){
			ans++;
			use+=lf;
		}else{
			break;
		}
	//	cout<<abs(a[x]-a[i])<<" ";
	}
	return ans+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);   
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		int _max=-1;
		for(int i=1;i<=n;i++){
			_max=max(check(i),_max);
		//	cout<<check(i)<<endl;
		}
		cout<<_max;
		return 0;
	}
	long long use=0,ans=1,_max=-1,st=1;
	for(long long i=2;i<=n;i++){
		use+=(i-st)*(a[i]-a[i-1]);
		if(use<=m){
			ans++;
		}else{
			for(;use>m;st++){
				use-=a[i]-a[st];
				ans--;
			}
			ans++;
		}
		_max=max(_max,ans);
	}
	cout<<_max;
	return 0;
}
