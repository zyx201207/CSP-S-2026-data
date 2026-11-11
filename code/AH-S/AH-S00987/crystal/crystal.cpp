#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500001;
int a[N],b[N],c[N],ans,cnt=1,v,n,m;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m>10000000000){
		int x=1;
		while((a[2]-a[1])*(x+1)*x\2<=m&&x<n){
			x++;
		}
		cout<<x;
		return 0;
	}
	c[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	int l=1;
	v=0;
	for(int i=2;i<=n;i++){
		v+=(i-l)*b[i];
		if(v>m){
			ans=max(ans,cnt);
			while(v>m&&l<i){
				v-=c[i]-c[l++];
			}
			cnt=i-l+1;
		}
		else{
			cnt++;
		}
	}
	ans=max(ans,cnt);
	cout<<ans;
}
