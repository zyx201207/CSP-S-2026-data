#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],hd[200001],hdc;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],hd[++hdc]=a[i];
	if(n==m){
		for(int i=2;i<=n;i++)a[1]&=a[i];
		cout<<a[1],exit(0);
	}
	for(int j=29;~j;j--){
		int cnt=0;
		for(int i=1;i<=hdc;i++)cnt+=(hd[i]&(1<<j))>0;
		if(cnt>=m){
			cnt=0;
			for(int i=1;i<=hdc;i++)if(hd[i]&(1<<j))hd[++cnt]=hd[i];
			hdc=cnt;
		}
		if(hdc==m){
			for(int i=2;i<=hdc;i++)hd[1]&=hd[i];
			cout<<hd[1],exit(0);
		}
	}
	for(int i=2;i<=m;i++)hd[1]&=hd[i];
	cout<<hd[1];
	return 0;
}
