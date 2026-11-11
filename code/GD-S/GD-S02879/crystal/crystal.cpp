#include<bits/stdc++.h>
using namespace std;
#define int long long
int rd(){
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){k*=10;k+=(c-'0');c=getchar();}
	return k*f;
}

const int N=5e5+7;

int n,m,a[N],s[N];


int get(int x){
	int l=1,r=x;
	int res=x;
	while(l<=r){
		int mid=(l+r)>>1;
//		cout<<(x-mid)*a[x]-(s[x-1]-s[mid-1])<<" : "<<mid<<"-"<<x<<'\n';
		if((x-mid)*a[x]-(s[x-1]-s[mid-1])<=m){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return x-res+1;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)ans=max(ans,get(i));
	cout<<ans;
	return 0;
} 
