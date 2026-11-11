#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m;
	cin>>n>>m;
	long long a[n]{},b[n]{};
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)b[i]=a[i]-a[i-1];
	for(int i=0;i<n;i++){
		long long cnt=0;
		int sum=0;
		for(int j=i;j<n;j++){
			sum++;
			cnt=cnt+b[j]*(sum-1);		
			while(b[j+1]==0){j+=1;sum++;}		
			if(cnt>=m)break;		
		}
		if(cnt==m)ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
