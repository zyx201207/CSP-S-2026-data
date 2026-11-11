#include<bits/stdc++.h>
using namespace std; 
long long int n,m,ans;
long long int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n+1);
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}


