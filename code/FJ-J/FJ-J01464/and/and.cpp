#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	while(m--){
		n--;
		ans=ans & a[n];
	}
	cout<<ans;
	return 0;
}
//ÎÒÊÇsz
//Ô¤ÆÚ10
//11:01
