#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],maxx=-1,cnt=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
		maxx=max(a[i],maxx);
	}
	cout<<maxx;
	return 0;
	}
	maxx=1;
	if(m==n){
		for(int i=1;i<=n;i++){
		maxx=maxx&a[i];
	}
	cout<<maxx;
	return 0;
	}
	maxx=-1;
	if(m==2){
		for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
 	      }
 	maxx=-1;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				cnt=cnt&a[j];
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	maxx=1;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(m==0)break;
		maxx=maxx&a[i];
		m--;
	}
	cout<<maxx;
	return 0;
}
