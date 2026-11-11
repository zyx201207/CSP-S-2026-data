#include<bits/stdc++.h> 
using namespace std;
long long a[200005],n,k,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	int j=1;
	for(int i=n-1;j<k;i--){
		ans&=a[i];
		j++;
	}
	cout<<ans;
	return 0;
}
