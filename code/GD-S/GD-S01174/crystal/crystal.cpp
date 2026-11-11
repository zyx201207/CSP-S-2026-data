#include <bits/stdc++.h>
using namespace std;

long long a[500010],n,m,mx;
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	int x=1;
	for(int i=3;i<n;i++) if(b[i]-b[i-1]!=b[i+1]-b[i]) x=0;
	if(x==1){
		int sum=0,mark=b[2],cnt=0;
		while(sum<=m) sum=sum*2+mark,cnt++;
		cout<<cnt;
		return 0;
	}
	for(int i=n;i>=2;i--){
		long long sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j],cnt++;
			if(sum>m) break;
			if(cnt>mx) mx=cnt;
		}
	}
	cout<<mx;
	return 0;
} 
