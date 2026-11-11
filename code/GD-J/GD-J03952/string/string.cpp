#include<bits/stdc++.h>
using namespace std;

long long n,a[200005],len,pu[200005],pd[200005];
long long ans;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		len+=a[i];
		pu[i]=pu[i-1]+a[i];
		c[i]-='a'-1;
	}
	pd[n]=a[n];
	for(int i=n-1;i>=1;i--){
		pd[i]=pd[i+1]+a[i];
	}
	int l=1,r=n;
	for(int i=1;i<=len/2;i++){
		if(i>pu[l]) l++;
		if(i>pd[r]) r--;
		if(c[l]!=c[r]) ans++;
	}	
	cout << ans;
	return 0;
}

