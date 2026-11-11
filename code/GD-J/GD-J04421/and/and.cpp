#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001000],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a[0]=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]&a[0]);
		}
		cout<<maxx;
	}else if(m==n){
		maxx=a[0];
		for(int i=1;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}else{
		cout<<maxx;
	}
	return 0;
} 
