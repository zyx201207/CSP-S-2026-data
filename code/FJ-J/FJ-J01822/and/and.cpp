#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1123456];
map<long long,long long> t;  
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			t[a[i]&a[j]]++;
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	for(int i=maxx;i>0;i--){
		if(t[i]==m){
			cout<<t[i];
			break;
		}
	}
	return 0;
}
/*
4 2 
3 15 12 12 
5 3
31 3 1 15 7

*/
