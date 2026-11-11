#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	b=a[n-1];
	for(int i=1;i<m;i++){
		b=b-b^a[n-i-1];
	}cout<<b;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
