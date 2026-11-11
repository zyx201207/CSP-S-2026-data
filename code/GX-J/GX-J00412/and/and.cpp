#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1,sum=1,c[200010];
long long f[31];
struct node{
	long long x,y;
};
node a[200010];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		for(int j=30;j>=0;j--){
			if(a[i].x>=(1<<j)){
				f[j]++;
				a[i].y=j;
				break;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=30;i++){
		if(f[i]>=m) maxx=max(maxx,i);
	}
	if(maxx==-1){
		long long ans=a[1].x;
		for(int i=2;i<=m;i++){
			ans=(ans&a[i].x);
		}
		cout<<ans;
	}
	else {
		long long cnt=m,ans;
		bool vis=0;
		for(int i=n;i>=1;i--){
			if(a[i].y==maxx){
				if(!vis){
					 vis=1;
					 ans=a[i].x;
					 cnt--;
				 }
				else {
					ans=(ans&a[i].x);
					cnt--;
				}
			}
			if(cnt==0) break;
		}
		cout<<ans;
	}
return 0;
}
