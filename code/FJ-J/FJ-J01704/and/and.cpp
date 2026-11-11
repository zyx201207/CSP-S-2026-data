#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[200008],ans,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n;i>=n-m;i--){
		k=a[i];
		for(int j=i-1;j>i-m;j--){
			k=k&a[j];
		}
		ans=max(k,ans);
		if(k>a[i-1]) break;
	}
	cout<<ans<<endl;
	return 0;
}
