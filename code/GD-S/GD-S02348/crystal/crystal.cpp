#include<bits/stdc++.h>

using namespace std;

long long m,n,a[500007],ans=1;

clock_t st=clock();

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	double tm;
	for(long long j=a[n];j>=a[1];j--){
		
		long long t=j,cnt=0,sum=0,s;
		
		for(int i=n;i>=1;i--){
			if(t>=a[i]){
				s=i;
				break;
			}
		}
		for(int i=s;i>=1;i--){
			sum+=(t-a[i]);
			if(sum>m)break;
			cnt++;
		}
		ans=max(ans,cnt);
		tm=double(clock()-st)/CLOCKS_PER_SEC;
		if(tm>0.9)break;
	}
	cout<<ans;
	return 0;

}



