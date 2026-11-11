#include<bits/stdc++.h>
using namespace std;
long long a[501010];
long long n,m;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long k=0;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==2){
			k=a[i]-a[i-1];
		}
		if(i>2){
			if(a[i]-a[i-1]!=k){
				flag=1;
			}
		}
	}
	if(!flag){
		k=a[n];
		for(int i=n-1;i>=1;i--){
			int tmp=k-a[i];
			if(m-tmp>=0){
				m-=tmp;
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans+1<<endl;
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int res=0;
		cnt=0;
		for(int j=i;j>=1;j--){
			cnt+=(a[i]-a[j]);
			if(cnt>m){
				break;
			}
			res++;
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

