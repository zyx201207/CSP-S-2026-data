#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[10001],c[10001];
long long m; 

int dj(int b)
{
	int z=0;
	for(int i=0;i<b+1;i++){
		z=z+a[i];
	}
	return z;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
	 	cin >> a[i];
	}
	for(int i=n;i>=0;i--){
		c[i]=dj(i);
	}
	for(int i=0;i<n;i++){
		int x=c[i]+m;
		if(x%a[i]==0){
			ans++;
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
