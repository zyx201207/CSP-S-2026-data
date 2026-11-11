#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;
	int f=1;
	char c=getchar();
	if(c=='-') f=-1;
	else x=(c^48);
	while(1){
		char c=getchar();
		if(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48);
		else break;
	}
	return x*f;
}
int n,k;
const int N=5e5+10;
int a[N],s[N];
int ans=-1;
int ask(int l,int r){
	return s[r]-s[l-1];
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();
	k=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i+1,p=i+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-ask(mid,i)<=k){
				p=min(p,mid);
				r=mid;
			}	
			else l=mid+1; 
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}

