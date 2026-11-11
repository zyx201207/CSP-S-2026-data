#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600860];
long long b[600860];
long long ans=1,maxn=0,h=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==1){
		h=n/2+1;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]>0){
				b[i]=a[i]-a[1];
			}else{
				b[i]=(a[i]-a[1])*-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]-b[h]>0){
				b[i]=b[i]-b[h];
			}else{
				b[i]=(b[i]-b[h])*-1;
			}
		}
	}else{
		h=n/2;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]>0){
				b[i]=a[i]-a[1];
			}else{
				b[i]=(a[i]-a[1])*-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]-b[h]>0){
				b[i]=b[i]-b[h];
			}else{
				b[i]=(b[i]-b[h])*-1;
			}
		}
	}
	while(m){
		long long min1=INT_MAX,h1=0,min2=INT_MAX,h2=0;
		for(int i=2;i<=n;i++){
			if(min1>b[i]){
				h2=h1;
				min2=min1;
				h1=i;
				min1=b[i];
			}
		}
		b[h1]=INT_MAX;
		b[h2]=INT_MAX;
		maxn+=min1;
		if(maxn<=m){
			ans++;
		}else{
			break;
		}
		maxn+=min2;
		if(maxn<=m){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
