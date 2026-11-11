#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
int wei;
ll ans; 
int main(){
	freopen("and.in","r",stdin);
	ll n ,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int wei = log2(a[n]);
	/*
	float di1 = log2(a[n]);
	if(di1 >di){
		wei = di+1;
	}
	else{
		wei = di;
	}
	*/
	//cout<<wei<<endl;
	int maxi =n;
	for(int i =wei;i>=0;i--){
		ll t=1;
		for(int j=1;j<=i+1;j++){
			t*=2;
		}
		t-=1;
		//cout<<t<<endl;
		ll t1=1;
		for(int j=1;j<=i;j++){
			t1*=2;
		}
		//cout<<t1<<endl;
		for(int j=n;j>=0;j--){
			if(a[j]<=t){
				maxi =j;
				break;
			}
		}
		//cout<<maxi<<endl;
		if(a[maxi-m+1]<t1){
			for(int j= maxi;j>=maxi-m+1;j--){
				if(a[j]<t1) break;
				a[j] -= t1;
				//cout<<"Y"<<" "<<a[j]<<" "<<j<<endl; 
			}
			sort(a+1,a+1+n);
			/*
			for(int j=1;j<=n;j++){
				cout<<a[j]<<" ";
			}
			cout<<endl;
			*/
			continue;
		}
		/*
		for(int j=1;j<=n;j++){
				cout<<a[j]<<" ";
			}
		cout<<endl;
		*/
		ans =a[n];
		for(int j=n;j>=n-m+1;j--){
			ans &= a[j];
		}
		break;
		 
		
		
		
		
	}
	cout<<ans<<endl;
	freopen("and.out","w",stdout);
	return 0;
}
