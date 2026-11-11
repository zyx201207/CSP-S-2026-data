#include<bits/stdc++.h> 
using namespace std;
const int N=500005;
long long n,m,a[N];
long long i,j,an[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(i = 2;i <= n;i++){
		for(j = 1;j <= i;j++){
			if(a[i]-a[j] <= m && a[i]>a[j]) m -= a[i]-a[j],a[j] = a[i],an[i]++;
		}an[i]=0;
		for(j = 1;j <= i;j++){
			if(a[j]==a[i]) an[i]++;
		}
	}
	sort(an+2,an+n+1);
	cout << an[n];	
	return 0;
}
