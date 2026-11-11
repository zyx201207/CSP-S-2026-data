#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[200005];
	int qq=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=n;i>n-m+1;i--){
		ans=min(a[i],a[i-1]);
		qq++;
		//cout<<a[i]<<endl;
	}
	
	
	cout<<ans;
	//cout<<endl<<qq;
	//cout<<"12345"<<3 and 15;
	return 0;
} 
