//GZ-J00670 兴义市弘毅中学 罗金浩 
#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200050],i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<a[m-1];
	return 0;
}
