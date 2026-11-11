//GZ-J00194 遵义市第十九中学 向博熙 
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long a[10005],b[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		a[i]=x;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		s=a[i]&a[i];
	}
	cout<<s;
	return 0;
}
