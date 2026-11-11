#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,a[314514],k[35],num,z,o=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o=max(a[i],o);
		int w=1;
		for(int j=1;j<=30;j++){
			if(a[i] & w){
				k[j]++;
			}
			if(w>a[i])break;
			w*=2;
		}
	}
	int w=(int)pow(2,30);
	z=m;
	for(int j=30;j>=1;j--){
		if(k[j]>=m){
			num+=w;
			z--;
			if(z==0)break; 
		}
		if(z==0)break; 
		w/=2;
	}
	if(m==1)cout<<o;
	else if(m==2){
		int p=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				p=max(p,a[i] & a[j]);
			}
		}
		cout<<p;
	} 
	else cout<<num/2;
	return 0;
}
/*

*/

