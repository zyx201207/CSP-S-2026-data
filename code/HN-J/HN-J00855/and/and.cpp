#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt,ans;
int a[N];
int st[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int t=0;
		for(int j=1;j<=n;j++){
			if(st[j]==cnt&&(a[j]&(1<<i))) t++;
		}
		if(t>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(st[j]==cnt&&(a[j]&(1<<i))) st[j]++;
			}
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}

