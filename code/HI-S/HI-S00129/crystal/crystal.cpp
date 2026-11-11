#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=a[n/2+1];
	for(int i=n/2+1;i>=1;i--){
		if(m>0){
			a[i]=mid;
			m=m-(mid-a[i]);
		}else{
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){ 
		if(a[i]==a[i-1]){
			a[i]=a[i-1]+a[i];
			a[i-1]=0;
			ans++;
		}
	}
	cout<<ans; 
	return 0;
}
//爱意随风起，风止意难平 
