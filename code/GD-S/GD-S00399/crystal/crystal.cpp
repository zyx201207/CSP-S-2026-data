#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+7;
int n,m,res=0;
int a[N],s[N];

int get(int l,int r){
	return s[r]-s[l-1];
}


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int tmp=m;
		int l=1,r=i-1,mid,siz=0;
		while(l<r){
			mid=(l+r)>>1;
			siz=(i-1)-mid+1;
			if(tmp-siz*a[i]+get(mid,i-1)>=0){
				r=mid;
			} else l=mid+1;
		}
		res=max(res,i-l+1);
	}
	cout<<res<<'\n';
	
	return 0;
} 
