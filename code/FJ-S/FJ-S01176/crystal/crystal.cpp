#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[600005];
int su[600005];
int cha[600005];
bool check(int l,int r){
	int res=(su[r]-su[l])-((a[r+1]-a[l+1])*l);
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		su[i]=su[i-1]+cha[i]*i;
		//cout<<su[i]<<"| ";
	}
	//cout<<"\n";
	int ans=0;
	for(int i=1;i<n;i++){
		int l=0,r=i,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			
			if(check(mid,i)){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(i-res+1,ans);
	}
	printf("%lld",ans);
} 
