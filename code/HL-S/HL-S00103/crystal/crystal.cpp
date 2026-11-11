#include<bits/stdc++.h>
using namespace std;
long long n,m,a[520000],fr,en,ans,mmax,ch[520000],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		ch[i]=a[i]-a[i-1];
	}
	fr=1;
	en=1;
	sum=0;
	ans=1;
	while(en<n){
		en++;
		sum=sum+ans*ch[en];
		ans++;
	//	cout<<fr<<" "<<en<<" "<<sum<<" "<<ans<<endl;
		if (sum>m){
			while(fr<en){
				sum=sum-(a[en]-a[fr]);
				fr++;
				ans--;
				if (sum<=m){
					break;
				}
			}
		}
		mmax=max(ans,mmax);
	}
	/*for(int i=1;i<=n;i++){
		long long sum=0;
		ans=0;
		for (int j=i-1;j>=1;j--){
			sum=sum+a[i]-a[j];
			if (sum>m){
				break;
			}
			ans++;
		}
		mmax=max(mmax,ans+1);
	}*/
	cout<<mmax;
	return 0;
}
