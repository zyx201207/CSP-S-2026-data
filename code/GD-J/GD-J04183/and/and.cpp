#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ans<(a[i]&a[j]))ans=a[i] & a[j];
			cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
