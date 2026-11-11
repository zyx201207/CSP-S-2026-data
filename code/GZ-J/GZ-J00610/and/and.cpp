//GZ-J00610贵阳市第十八中学王梓钰
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1];
	fclose(and.in);
	fclose(and.out);
	return 0;
}
