#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,pos,pre[500010],v,ans=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	v=a[1];
	for(int i=1;i<=n;i++) {
		if(v<0){
			a[i]+=(-v);
		}
		pre[i]=pre[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		pos=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(pre[i-1]-pre[mid-1])<=m){
				r=mid-1;
				pos=mid;
			}else l=mid+1;
		}
	//	cout<<i<<" "<<pos<<"\n";
		if(pos!=-1) ans=max(ans,i-pos+1);
	}
	cout<<ans;
	
	return 0;
} 
