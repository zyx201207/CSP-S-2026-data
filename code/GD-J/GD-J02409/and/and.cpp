#include<bits/stdc++.h>
using namespace std;
int n,m,ge;
int a[200005],tim[200005],vis[200005];
long long sum;
int times(int x){
	int cnt=0;
	while(x){
		cnt++;
		x/=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>0;i--){
		tim[i]=times(a[i]);
	}
	for(int i=tim[n-1];i>=0;i--){
		int cnt=0;
		for(int j=n-1;j>=0;j--){
			if(a[j]&(1<<i-1)) {
				cnt++;
				if(vis[j]==0) ge++;
				vis[j]++;
			}
			if(cnt>=m){
				if(ge>m) break;
				sum+=(1<<i-1);
				break;
			}
		}
	}
	cout<<sum;
	return 0;
} 
