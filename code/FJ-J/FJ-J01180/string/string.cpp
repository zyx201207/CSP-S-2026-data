#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,za,zb,ga=0,gb=0,s=0,k;
	long long a[200005];
	char c[200005];
	cin>>n; 
	za=1;
	zb=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(za<zb){
		if(c[za]!=c[zb]){
			s+=min((a[za]-ga),(a[zb]-gb));
		}
		k=min((a[za]-ga),(a[zb]-gb));
		ga+=k;
		gb+=k;
		if(ga==a[za]){
			ga=0;
			za++;
		}
		if(gb==a[zb]){
			gb=0;
			zb--;
		}
	}
	cout<<s;
	return 0;
}
