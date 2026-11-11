#include<bits/stdc++.h>
using namespace std;
long long n,m,a[614514],b[614514],c[614514],shu;
int daan,ge;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		while(shu+b[i]*ge>m&&ge){
			shu=shu-a[i-1]+a[i-ge];
			ge--;
		}
		if(!ge){
			ge++;
			continue;
		}
		shu+=ge*b[i];
		ge++;
		daan=max(daan,ge);
	}
	daan=max(daan,1);
	cout<<daan;
	return 0;
} 
