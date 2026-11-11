#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	bool flag1=true,flag2=true;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i) flag1=false;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2] && i>=3) flag2=false;
	}
	if(flag1){
		int cnt=0;
		for(int i=1;i<=m;i++) {
			m-=i;
			cnt++;
		}
		cout << cnt+1;
	} else if(flag2){
		int cnt=0;
		for(int i=1;i<=m;i+=a[2]-a[1]) {
			m-=i;
			cnt++;
		}
		cout << cnt+1;
	} else {
		sort(a+1,a+n+1);
		int t=m,mx=-1;
		for(int i=a[1];i<=a[n];i++){
			t=m;
			int cnt=0;
			for(int j=1;j<=n;j++){
				//cout << t << ' ' << i << ' ' << mx << ' ' << cnt << endl;
				if(a[j]<i && t-i+a[j]>=0){
					t-=i-a[j];
					cnt++;
					//cout << a[j] << '-' << cnt << endl;
				}
				if(a[j]==i) cnt++;
				if(a[j]>i) break;
			}
			mx=max(cnt,mx);
		}
		cout << mx;
	}
	return 0;
}
