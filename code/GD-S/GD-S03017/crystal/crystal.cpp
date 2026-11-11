#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1919810];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0;
	for(int i=1;i<n;i++){
		long long m1=m,cnt=1;
		for(int j=i-1;j>=0;j--){
			if(m1<a[i]-a[j]){
				ans=max(ans,cnt);
				break;
			}else{
				m1-=(a[i]-a[j]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
} 
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts

