#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500005],pr[500005],pr2[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		pr[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		pr2[i]=pr[i]+pr2[i-1];
	}
	int i=0,j=1;
	int ans=0;
	ll s=pr[1];
	while(j<n){
	    if(s<=m){
	    	ans=max(ans,j-i+1);
	    	j++;
	    	s+=pr[j]*(j-i);
		}else if(i<=j){
		    i++;
			s-=(pr2[j]-pr2[i-1]);
		} 
		else{
		    j++;
			s+=pr[i]*(j-i);	
		} 
	}
	cout<<ans;
	return 0;
}

