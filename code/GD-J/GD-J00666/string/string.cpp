#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	unsigned long long num[n+5],mid=0,ans1=0,ans2=0;
	char a[n+5];
	unsigned long long pre[n+5];
	pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
		mid+=num[i];
		pre[i]=pre[i-1]+num[i];
	} 
	bool f=true;
	if(mid%2==0){
		mid/=2;
		f=false;
	}
	else mid=pre[n]/2+1;
	for(long long i=1;i<=n;i++){
		if(pre[i]<=mid){
			if(f&&pre[i]==mid) continue;
			unsigned long long idx=lower_bound(pre+1,pre+n+1,pre[i]+mid)-pre;
			if(a[idx]!=a[i]) ans1+=num[i];
		}
		else{
			unsigned long long idx=lower_bound(pre+1,pre+n+1,pre[i]-mid)-pre;
			if(a[idx]!=a[i]) ans2+=num[i];
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
