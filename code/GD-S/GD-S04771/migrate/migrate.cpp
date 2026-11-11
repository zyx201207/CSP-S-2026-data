#include<bits/stdc++.h>
using namespace std;
int Case_Num;
int n;
int cnt[100005],f[100005];
long long d,x[100005];
int calc(const int &start_idx){
	for(int i=start_idx+1;i<=n;++i)
		f[i]=500000,cnt[i]=0;
	f[start_idx]=0,cnt[start_idx]=1;
	int sum=0,l=start_idx;
	for(int i=start_idx+1;i<=n;++i){
		while(l<i&&x[i]-x[l]>d) ++l;
		f[i]=f[l]+1;
		for(int j=l;j<min(i,l+3);++j)
			if(f[j]+1==f[i]) cnt[i]+=cnt[j];
		if(cnt[i]==2) ++sum;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;
	cin>>Case_Num>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>x[i];
		long long Ans=0;
		for(int i=1;i<=n;++i)
			Ans+=calc(i);
		cout<<Ans<<'\n';
	}
	return 0;
}
