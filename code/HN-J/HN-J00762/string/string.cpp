#include<bits/stdc++.h>
using namespace std;
struct sn{
	int x;
	char c;
}a[200005];
int n,x,ans,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(cnt<n-1){
		if(a[l].c!=a[r].c){
			int d=min(a[l].x,a[r].x);
			ans+=d;
			a[l].x-=d;
			a[r].x-=d;
		}else{
			int d=min(a[l].x,a[r].x);
			a[l].x-=d;
			a[r].x-=d;
		}
		if(a[l].x==0){
			cnt++;
			l++;
		}
		if(a[r].x==0){
			cnt++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
