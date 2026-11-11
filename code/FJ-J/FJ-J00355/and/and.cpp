#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];
void js(){
	return;
}
void f(int wz,int sl){
	if(wz==m+1){
		js();
		cout<<endl;
		return ;
	}
	for(int i=sl;i<=n;i++){
		b[wz]=a[i];
		f(wz+1,sl+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0,1);
	return 0;
}
