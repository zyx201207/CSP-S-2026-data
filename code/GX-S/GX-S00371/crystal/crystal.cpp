#include<bits/stdc++.h>
using namespace std;
long long a[50000005];
long long cnt[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	int cnt1,cnt2;
	int p;
	int o=0;
	long long minn=10000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(m!=0){
		cnt1=0;
		cnt2=0;
		minn=10000000;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				int t=abs(a[i]-a[j]);
				if(t<minn && t!=0){
					minn=t;
					cnt1=i;
					cnt2=j;
					p=min(cnt1,cnt2);
				}
				
			}
		}
		a[p]++;
		m--;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])
		{
			cnt[o]++;
			o++;
		}
	}
	cout<<o+1;
	return 0;
}
