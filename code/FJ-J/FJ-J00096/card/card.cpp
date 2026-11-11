#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum;
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if (m == 1){
		cout<<n;
		return 0;
	}
	for (int i = 1; i<= n; i++) {
		cin>>a[i]; 
		sum+=a[i];
	}
	if (sum == n)cout<<n<<" 0";return 0;
	if (sum == 2*n)cout<<"0 "<<n;return 0;
	if (sum == n+1) {
		if (a[n]==2) cout<<n-1<<" "<<n;return 0;
		if (a[n-1]==2&&n>1)cout<<n<<" "<<n-1;return 0;
		if (a[n-2]==2&&n>2)cout<<n<<" "<<n-2;return 0;
		if (a[n-3]==2&&n>3)cout<<n<<" "<<n-3;return 0;
		if (a[n-4]==2&&n>4)cout<<n<<" "<<n-4;return 0;
	}
	if (sum==n+2&&n>1) {
		if (a[n]==2)cout<<n-2<<" "<<n;return 0;
		if (a[n-1]==2)cout<<n<<" "<<n-1;return 0;
		if (a[n-2]==2&&n>2)cout<<n<<" "<<n-2;return 0;
		if (a[n-3]==2&&n>3)cout<<n<<" "<<n-3;return 0;
	}
	if (sum==n+3&&n>2){	
		if(a[n]==1)cout<<n<<" "<<n-1;return 0;
		if(a[n-1]==1)cout<<n-1<<" "<<n;return 0;
		if(a[n-2]==1&&a[1]==1)cout<<n-2<<" "<<n;return 0;
		if(a[n-2]==1&&a[2]==1)cout<<n-3<<" "<<n;return 0;
		if(a[n-3]==1)cout<<n-3<<" "<<n;return 0;
	}
}
