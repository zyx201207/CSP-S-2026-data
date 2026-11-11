#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,h=0,l;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){ 
		cin>>a[i];
		} 
	sort(a,a+n);
	for(int i=0;i<n;i++){
	l=0;
			for(int j=0;j<i;j++){ 
			l=l+a[i]-a[j];
			} 
			if(l<=m&&a[0]<=m){ 
			h=i+1;
			} 
	}
	cout<<h;
	return 0;
}
 
