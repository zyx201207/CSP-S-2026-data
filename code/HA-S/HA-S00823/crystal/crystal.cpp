#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,b[1000000],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long max=0;
	sort(a,0+a+n);
	max=a[0]+m;
	for(int i=0;i<n;i++){
		if(max>a[i]){
			
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
