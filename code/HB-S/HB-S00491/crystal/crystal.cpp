#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[500009];
bool ck(long long su){
	long long fvc;
	for(int kl=1;kl<=n-su+1;kl++){
		if(kl==1){
			fvc=a[kl+su-1]*(su-1)-(b[kl+su-2]-b[kl-1]);
		}else{
			fvc=min(a[kl+su-1]*(su-1)-(b[kl+su-2]-b[kl-1]),fvc);
		}		
	}
	if(fvc<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long ri=n+1,le=1,mid;
	while(ri>le){
		mid=le+(ri-le)/2;
		if(ck(mid)){
			le=mid+1;
		}else{
			ri=mid;
		}
	}
	cout<<ri-1;
	return 0;
}
