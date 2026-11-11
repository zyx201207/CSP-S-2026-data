#include <bits/stdc++.h>
using namespace std;
long long a[500009];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	long long s=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=0,x=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			x++;
			
			if(sum>m){
				break;s=max(s,x);
			}
			s=max(s,x);
		}
	}
	cout << s;
	return 0;
}
