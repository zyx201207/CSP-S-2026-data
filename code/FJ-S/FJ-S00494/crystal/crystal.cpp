#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int maxs=0;
	for(int i=1;i<=n;i++){
		long long x=m;
		bool p=0; 
		for(int j=i;j>=1;j--){
			if(x<a[i]-a[j]){
				maxs=max(i-j-1,maxs);
				p=1;
				break;
			}
			x-=a[i]-a[j];
		}
		if(p==0)maxs=max(i,maxs);
		
	}
	cout<<maxs;
	return 0;
}
