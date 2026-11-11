//GZ-s00382 Ã∑‚˘≈Ù  
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int x=0;x<n;x++)cin>>a[x];
	long long s=0,sb=0;
	int x=0,y=1,z=1;
	sort(a,a+n);
	while(y<n){
		if(sb<=m){
			if(s<z)s=z;
			sb+=(a[y]-a[y-1])*(y-x);
			y++;
			z++;
		}
		else{
			sb-=a[y-1]-a[x];
			x++;
			z--;
		}
	}
	cout<<s<<endl;
	return 0;
} 
