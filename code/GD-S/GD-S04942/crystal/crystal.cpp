#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s,z,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a,a+n+1);
	for(long long i=2;i<=n;i++){
		s=0;
		z=0;
		for(long long j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m) break;
			z++;	
		}
		ma=max(z,ma);
	}
	cout<<ma+1;
	return 0;
} 
