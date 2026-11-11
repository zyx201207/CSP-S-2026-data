#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,tl,v[500100],qn[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		qn[i]=v[i]+qn[i-1];
	}
	ll l,r,mid,ans=0;
	for(int i=1;i<=n;i++){
		l=0;r=i-1;//l²»Òª£¬rÒª 
		tl=v[i]*(i-1)-qn[i-1];
		while(l<=r){
			mid=(l+r)/2;
			tl=v[i]*(i-mid)-(qn[i]-qn[mid]);
			if(tl>m){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,i-l);
	}
	printf("%lld",ans); 

	return 0;
} 

