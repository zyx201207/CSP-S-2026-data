#include<bits/stdc++.h>
using namespace std;
long long a[2000009],n,m,maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		maxx=a[1]&a[2];
		for(int i=3;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<int(maxx);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<int(maxx);
		return 0;
	}
	return 0;
}
