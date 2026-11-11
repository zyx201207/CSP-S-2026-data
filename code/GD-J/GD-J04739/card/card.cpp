#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int q[500005];
int s[500005];//当前遇到几个 
int ans[500005];
int sum[5000
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],q[a[i]]++;
	if(m==1){
		cout<<1<<endl;
		return 0;
	}
	if(m==2){
		long long k=0;
		int c=0;
		for(int i=n;i>=1;i--){
			if(a[i]==1) k+=i,c++;
			if(a[i]==2) k+=i,c++;
			if(c>=2) break;
		}
		cout<<k<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k=i;
		if(i==n) {
			sum[a[i]]+=i;
			continue;
		}
		s[a[i]]++; 
		if(s[a[i]]<q[a[i]]) continue;//后面有一样的，无贡献
		if(q[a[i]]==s[a[i]]) {
			ans[i]+=q[a[i]];
			sum[a[i]]+=q[a[i]];
			continue;
		}
		if(ans[i-1]==0&&a[i]!=a[i-1]) {
			ans[i]=1;
			sum[a[i]]+=ans[i];
			continue;
		}
	}
	//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	//cout<<endl;
	for(int i=1;i<500004;i++) 
		if(q[i]) cout<<sum[i]<<" ";
	cout<<endl;
	
	return 0;
}




