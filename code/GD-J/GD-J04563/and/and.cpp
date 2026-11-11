/*
I love CCF
求你了给我分吧我真的不会我不找别人索命了给我20分吧 
3000行分来怎么超限了我哭了 
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20005];
long long maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
	}
	long long x=a[1],ma=0;
	for(int i=2;i<=n;i++){
		x&=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long t=i&j;
			if(t>ma){
				ma=t;
			}
		}
	}
	if(m==1){
	cout<<maxx;
	}else if(m==2){
		cout<<ma;
	}else if(m==n){
		cout<<x;
	}
	return 0;
}
