#include <bits/stdc++.h>
using namespace std;
int a[100000000],s[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int mx=-1,l,r;
	for(int i=1;i<=n;i++){
		l=i+1;
		r=i+m+1;
		while(l<=r){
			s[i]=a[l]&a[l-1];
			l++;
		}
	} 
	for(int i=1;i<=n;i++){
		mx=max(mx,s[i]);
	}
	cout<<mx;
	return 0; 
}
