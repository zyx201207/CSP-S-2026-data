#include<bits/stdc++.h>
using namespace std;
int a[100005],m,n,m1,ans=1,b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b=1;
		m1=m;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=m1){
				m1-=(a[i]-a[j]);
				b++;
			}
		}
		if(ans<b){
			ans=b;
		}
	}
	cout<<ans;
	return 0;
}
