#include<bits/stdc++.h>
using namespace std;
#define inta long long
inta n,m,ans;
inta a[500050];
bool ch(inta p){
	inta s=0;
	for(inta i=1;i<=p;i++){
		s+=a[p]-a[i];
	}
	if(s<=m) return 1;
	for(inta i=1;p+i<=n;i++){
		s-=a[p+i-1]-a[i];
		s+=(a[p+i]-a[p+i-1])*(p-1);
		if(s<=m) {
			return 1;
		}
	}
	return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(inta i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n,mid=0;
    while(l<=r){
    	mid=(l+r)/2;
    	if(ch(mid)){
    		l=mid+1;
    		ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?

