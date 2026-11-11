#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=500005;
int n;
ll m;
ll a[N],c[N],jf[N],lazy,q[N];
//原数组 后缀差分 相邻差值(减法) jf[i]=a[i+1]-a[i] 现在每个数据的懒惰标记 后缀差分的后缀和 
int ans=1; //最多是n 5e5 
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		jf[i]=a[i]-a[i+1];
		c[i]=a[n]-a[i];
	}
	for(int i=n;i>=1;i--) q[i]=q[i+1]+c[i];
//	for(int i=1;i<=n;i++) cout<<jf[i]<<' ';
	for(int i=n;i>=1;i--){//中心 
		int l=1,r=i;//第一个比m小的pos 
		int pos;
		while(l<=r){
			int mid=(l+r)/2;
			if(q[mid]+lazy*(n-mid+1)-q[i+1]-lazy*(n-i)<=m){
				pos=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
		//cout<<i<<':'<<pos<<endl;
		//for(int mid=1;mid<=i;mid++)cout<<q[mid]+lazy*(n-mid+1)-q[i+1]-lazy*(n-i)<<' ';
		//cout<<endl;
		lazy+=jf[i-1];
	}
	cout<<ans<<endl;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//crystal

//q[mid]+lazy*(n-mid+1)-q[i+1]-lazy*(n-i)
