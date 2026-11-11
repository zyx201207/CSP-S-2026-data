#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	long long n,m;
	long long a[200005];
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);int ans=a[n];
			for(int i=n-1;i>n-m;i--){
		ans&=a[i];
	}
	
cout<<ans;
	return 0;
}
