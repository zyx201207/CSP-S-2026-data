#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2*1e5;
int n,m,a[MAXN+5],maxx=-1;
int count(int x){
	int ans=0;
	for(int i=0;i<=30;i++){
		int r=(1<<i);
		if((x&r)==r) ans++;
	}
	return ans;
}
int bigg(int x){
	for(int i=30;i>=0;i--){
		int r=(1<<i);
		if((x&r)==r){
			return x;
		}
	}
	return 0;
}
bool cmp1(int a,int b){
	int c1=bigg(a);
	int c2=bigg(b);
	if(c1==c2){
		return count(a)>count(b);
	}
	return c1>c2;
}
bool cmp2(int a,int b){
	int c1=count(a);
	int c2=count(b);
	if(c1==c2){
		return bigg(a)>bigg(b);
	}
	return c1>c2;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp1);
	int ans=a[1];
	for(int i=1;i<=m;i++){
		//cout<<ans<< "&="<<a[i]<<"->";
		ans&=a[i];
		//cout<<ans<<endl;
	}
	maxx=max(ans,maxx);
	sort(a+1,a+1+n,cmp2);
	ans=a[1];
	for(int i=1;i<=m;i++){
		//cout<<ans<< "&="<<a[i]<<"->";
		ans&=a[i];
		//cout<<ans<<endl;
	}
	maxx=max(ans,maxx);
	cout<<maxx;
	return 0;
	
}
