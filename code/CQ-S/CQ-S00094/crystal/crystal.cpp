#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int main(){

	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[N];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int arr[N];
	for(int i=1;i<n;i++){
		arr[i] = a[i+1]-a[i];
	}
	int m1 = m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		int ans;
		for(int j=i+1;j<=n;j++){
			if(m1>=arr[j-1]*(j-1)) m-=arr[j-1]*(j-1);
			else break;
			ans = j-i+1;
		}
		maxx = max(maxx,ans);
	}	
	
	cout << maxx;

	return 0;
}


