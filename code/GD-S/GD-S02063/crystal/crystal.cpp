#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long m,a[500010];
long long c[500010],q[500010];
//priority_queue<asdf>pq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	//for(int i=1;i<=n;i++){
	//	c[i]=(a[i]-a[i-1])*i+c[i-1];
	//	q[i]=c[i]+q[i-1];
	//}
	int l=1,r=1,t=0;
	int ans=0;
	while(r<n){
		ans=max(ans,r-l+1);
		if(t+(r-l+1)*(a[r+1]-a[r])<=m){
			t+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		else{
			t-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
