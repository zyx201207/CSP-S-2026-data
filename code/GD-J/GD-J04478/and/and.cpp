#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) cout<<*max_element(a+1,a+n+1);
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	return 0;
}
