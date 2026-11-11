#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
bool cmp(int x,int y){
	return x>y;
}
long long pre[N];
long long ans[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=((1<<32)-1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(n<=2000){
		int l=1,r=m;
		long long cnt=((1<<32)-1);
		while(r<=n){
			cnt=((1<<32)-1);
			for(int i=l;i<=r;i++){
				cnt=cnt&a[i];	
			}
			ans=max(ans,cnt);
			l++,r++;
		}
		cout<<ans; 
	}else{
		long long cnt=((1<<32)-1);
		for(int i=1;i<=m;i++){
			cnt=cnt&a[i];
		}
		ans=max(ans,cnt);
		cnt=((1<<32)-1);

		if(m+1<=n){
			for(int i=2;i<=m+1;i++){
				cnt=cnt&a[i];
			}
			ans=max(ans,cnt);
		}

		cnt=((1<<32)-1);
		if(m+2<=n){
			for(int i=3;i<=m+2;i++){
				cnt=cnt&a[i];
			}
			ans=max(ans,cnt);
		}

		cnt=((1<<32)-1);
		if(m+3<=n){
			for(int i=4;i<=m+3;i++){
				cnt=cnt&a[i];
			}
			ans=max(ans,cnt);
		} 

		cnt=((1<<32)-1);
		if(m+4<=n){
			for(int i=5;i<=m+4;i++){
				cnt=cnt&a[i];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	
	return 0;
}
