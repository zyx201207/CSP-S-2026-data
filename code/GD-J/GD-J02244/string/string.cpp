#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+1];
	char c[n+1];
	long long ans=0;
	for(int cont=1;cont<=n;cont++){
		
		cin >> a[cont] >> c[cont];
		ans+=a[cont];
	}
	int pan=0;
	for(int i=2;i<=n;i++){
		if(c[i-1]==c[i]){
			pan=1;
		}
		else{
			pan=0;
			break;
		}
	}
	if(pan==1){
		cout << 0;
		return 0;
	}
	ans=(ans+1)/2;
	for(int i=1;i<=n;i++){
		if(c[i]==c[n-i+1]){
			//ans-=(abs(a[i]-a[n-i+1])+1)/2;
			ans-=(min(a[i],a[n-i+1])+1)/2;
		}
		else if(c[i]==c[n-i] and a[i-1]<=a[n-i]){
			ans-=(a[n-1]-a[i-1])*2;
		}
	}
	cout << ans;
	return 0;
}
