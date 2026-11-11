//GZ-J00136 遵义市第十二中学  李明博 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,arr[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		
	}
	sort(arr,arr+n);
	ans=arr[n-1];
	for(ll i=n-1;i>=n-m;i--)ans&=arr[i];
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
