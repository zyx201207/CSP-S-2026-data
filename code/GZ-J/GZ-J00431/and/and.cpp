//GZ-J00431 贵阳一中李端棻中学 田贺铭 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n];
	return 0;
} 
