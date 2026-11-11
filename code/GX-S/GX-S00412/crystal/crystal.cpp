#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],x[500005],m,l,f,g;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		l=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[i]>=a[j]) l+=(a[i]-a[j]);
			else l+=(a[j]-a[i]);
		}
		x[i]=l;
		f=max(f,l);
	}
	for(int i=1;i<=n;i++){
		if(x[i]==f){
			g=i;
			break;
		}
	}
	sort(a+1,a+1+g);
	for(int i=g-1;i>=1;i--){
		if(m>=a[i]){
			m=m-(a[g]-a[i]);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
