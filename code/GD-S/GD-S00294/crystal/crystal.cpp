#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int ma=0;
	for(int i=n-1;i>=1;i--){
		long long t=0;
		int x=0;
		for(int j=i;j>=0;j--){
			t+=a[i]-a[j];
			x++;
			if(t>=m){
				ma=max(ma,x);
				break;
			}
		}
	}
	cout<<ma;
	return 0; 
}
