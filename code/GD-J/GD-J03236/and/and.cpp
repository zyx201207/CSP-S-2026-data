#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m,a[200007],ans,o;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	o=m;
	for(int i=n;i>=1&&m>=1;i--){
		if((ans&a[i])!=0) ans=a[i]&ans;
		else{
			//cout<<"x";
			ans=a[i];
			m=o;
		}
		m--;
		//cout<<a[i]<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 
