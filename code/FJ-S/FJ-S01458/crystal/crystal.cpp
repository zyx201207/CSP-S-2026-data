#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=555555;
LL n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl;
		a[i]+=a[i-1]; 
		
	}
	LL j=1;
	//[i,j]
	for(int i=1;i<=n;i++){
		//a[i]-a[j-1]
		while((LL(a[i]-a[i-1])*(i-j+1)-a[i]+a[j-1])>m&&j+1<=i)j++;
		if((a[i]-a[i-1])*(i-j+1)-a[i]+a[j-1]<=m){
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}  

 
