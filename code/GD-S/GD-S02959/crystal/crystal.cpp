#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],zf[500005];
map<int,int> mp;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		b[i]=a[i];
		zf[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	long long ma=0,k=0;
	for(auto i:mp){
		if(mp[i]>ma){
			ma=mp[i];
			k=i;
		}
	}
	
	long long l;
	l=m;
	for(int i=1;i<=n;i++){
		
	}
} 
