#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1e9,ans2=-1e9,a[1000005],ans1;
//int ;
int main(){
	
	
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans2=max(a[i],ans2);
	}
	if(m==1){
		cout<<ans2;
		return 0;
	}

	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			//cout<<a[i]<<" "<<a[j]<<" ";
			ans1=a[i] | a[j];
			ans=max(ans,ans1);
		}
	}
	//int g=int(a[3]) and int(a[4]);
	//cout<< a[3]<<a[4]<<g;
	//cout<<ans;
	cout<<a[n];
	//cout<<3 and 12 ;
	return 0;
} 
