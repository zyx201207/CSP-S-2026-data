#include<bits/stdc++.h>
using namespace std;
int n,m;
struct qaq{
	long long value;
	int os;
}a[1000001];
bool cmp(qaq x,qaq y){
	if(x.os!=y.os) return x.os>y.os;
	return x.value>y.value;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a[i].value=x;
		while(x){
			a[i].os+=x%2;
			x/=2;
		}
	}
	sort(a,a+n,cmp);
	cout<<a[m-1].value;
	return 0;
}
