#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],pre[N],ans=0;
char c[N];
vector<int>pos;
void init(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],pre[i]=pre[i-1]+a[i];
}
char qry(int idx){
	int l=1,r=n,mid,res=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(idx<=pre[mid])r=mid-1,res=mid;
		else l=mid+1;
	}
	return c[res];
}
void work(){
	init();
	int len=0;
	for(int i=1;i<=n;i++)len+=a[i];
	for(int i=1,sum=0;sum<len/2;i++){
		sum+=a[i];
		pos.push_back(min(sum,len/2));
	}
	for(int i=n,sum=0;sum<len/2;i--){
		sum+=a[i];
		pos.push_back(min(sum,len/2));
	}
	sort(pos.begin(),pos.end());
	for(int i=0,lst=0;i<pos.size();i++){
		int nw=pos[i];
		char c1=qry(nw),c2=qry(len-nw+1);
		if(c1!=c2)ans+=nw-lst;
		lst=nw;
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	work();
	return 0;
}
