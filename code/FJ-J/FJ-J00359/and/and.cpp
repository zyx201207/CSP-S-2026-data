#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200009];
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int s=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		s=s&a[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}