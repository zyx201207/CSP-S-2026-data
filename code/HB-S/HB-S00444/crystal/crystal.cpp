#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n;
	cin >> m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]<a[i]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		long long t=m;
		long long b=1;
		for(int j=i-1;j>=0;j--){
			t-=(a[i]-a[j]);
//			cout << t << ' ';
			if(t<0){
				break;
			}
			b++;
		}
		if(b>ans){
			ans=b;
		}
//		cout << endl;
	}
	cout << ans;
	return 0;
}
