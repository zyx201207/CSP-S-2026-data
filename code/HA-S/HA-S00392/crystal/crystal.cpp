#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+1001;
int a[N],b[N];
int n,m;
bool check(int l,int r,int w){//r是p,不算上 
	int w1=(r-l)*w;
	int w2=b[r-1]-b[l-1];
	//printf("最终值%d 区间%d to %d 理论区间和%d  实际区间和%d \n",w,r-1,l,w1,w2);
	//if(m>=w1-w2)printf("success \n");
	return m>=w1-w2;
}
int f(int p,int w){
	int l=1,r=p;
	int mid=(l+r)/2;
	int ans=0;
	while(l<r){
		mid=(l+r)/2;
		//printf("p is %d mid is %d\n",p,mid);
		if(check(mid,p,w)){
			r=mid;
			ans=p-mid;
		}
		else l=mid+1;
	}
	return 1+ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		b[i]=a[i]+b[i-1];
		ans=max(ans,f(i,a[i]));
	}
	cout<<ans<<endl;
	return 0;
}
