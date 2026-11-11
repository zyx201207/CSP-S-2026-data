#include <bits/stdc++.h>
using namespace std;
bool paixu(int a,int b){
	if(a>b)	return true;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long ans;
	cin >> n >> m;
	long long a[m];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	sort(a,a+n,paixu);
	ans=a[0];
	for(int i=0;i<m-1;i++){
		ans=ans&a[i+1];
	}
	cout << ans;
    return 0;
}
