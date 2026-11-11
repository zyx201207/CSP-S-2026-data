#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ma=0;
int a[500001];
long long h[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		h[i]=(a[i]-a[i-1])*(i-1)+h[i-1];
		long long s=h[i];
		for(int j=1;j<=i;j++){
			if(s<=m){
				ma=max(ma,i-j+1);
				break;
			}
			s-=(a[i]-a[j]);
		}
	}
	cout<<ma;
	return 0;
}
/*
8 5
8 1 4 2 3 7 6 5
*/
