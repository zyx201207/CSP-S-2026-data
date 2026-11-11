#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],ans,x,l;
bool t1=1,t2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			t1=0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			t2=0;
			break;
		}
	}
	if(t1==1){
		while(ans<=m){
			l++;
			ans+=l;
		}
		cout<<l;
		return 0;
	}
	if(t2==1){
		while(ans<=m){
			l++;
			ans+=(l*(a[2]-a[1]));
		}
		cout<<l;
		return 0;
	}
	for(int i=1;i<n;i++){
		while(x<=m){
			if(i+1+l>n){
				break;
			}
			x+=(a[i+1+l]-a[i+l])*(l+1);
			l++;
		}
		ans=max(ans,l);
		cout<<ans<<"\n";
		x=0;l=0;
	}
	cout<<ans;
	return 0;
}
