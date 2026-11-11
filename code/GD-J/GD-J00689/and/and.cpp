#include<bits/stdc++.h>
using namespace std;
const int INT=200005;
int a[INT];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[(n+1)/2];
	fclose(stdin);
	fclose(stdout);
}
