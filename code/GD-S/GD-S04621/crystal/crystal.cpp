#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long maxx=-1e9;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int m1=m,now=i;
		long long cnt=0;
		while(m1>=a[i]-a[now] && now>0){
			cnt++;
			m1=m1-(a[i]-a[now]);
			now--;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
