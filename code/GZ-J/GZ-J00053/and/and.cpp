//GZ-J00053 贵阳市第一实验中学 王果然
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
int main() {
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,n+1+a);
	cout<<a[n];
	return 0;
}
