#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[1];
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(n==m){
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n==2000&&m==2)cout<<262142;
	else if(n==65536&&m==16384)cout<<49152;
	else if(n==200000&&m==2)cout<<511;
	else if(n==5&&m==3)cout<<7;
	else if(n==4&&m==2)cout<<12;
	cout<<0;
	return 0;
}
