#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxx=0;
	for(int i=n;i>=1;i--){
//		for(int j=)
		if(m==2){
			maxx=max(a[i]&a[i-1],maxx);
		}
		if(m==1){
			maxx=a[n];
		}
		if(m==n){
			maxx=a[1];
			for(int j=1;j<n;j++){
				maxx=maxx&a[j];
			}
		}
		else{
			maxx=max(a[i]&a[i-1]&a[i-m+1],maxx);
		}
	}
	cout<<maxx<<endl;
	return 0;
}
