#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long qz[500005];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	a[0]=-1e18-7;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	int l=n;
	long long t=m;
	while(t>=0&&l){
		if(a[n]-a[l]<=t){
			t-=a[n]-a[l--];
		}else{
			break;
		}
	}
	l++;
	int an=n-l+1;
	for(int i=n-1;i;i--){
		t=m-(a[i]*(i-l+1)-(qz[i]-qz[l-1]));
		while(t>=0&&l){
			if(a[i]-a[l]<=t){
				t-=a[i]-a[l--];
			}else{
				l++;
				break;
			}
		}
		an=max(an,i-l+1);
	}
	cout << an-1;
	return 0;
}
/*
7 37
44 46 56 63 72 72 456
*/
