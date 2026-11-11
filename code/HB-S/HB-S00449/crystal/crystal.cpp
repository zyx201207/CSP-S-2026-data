#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,l,o;
	cin >> n >> m;
	long long a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a+n,a+n+1);
	o=m;
	for(int i=1;i<n;i++){
		l=o;
		o-=(a[i]-a[i-1])*i;
		if(o<0){
			if(i>((l/(a[i]-a[i-1]))+1))cout << i;
			else cout << ((l/(a[i]-a[i-1]))+1);
			return 0;
		}if(o==0){
			cout << i+1;
			return 0;
		}
	}
	cout << n;
	return 0;
}
