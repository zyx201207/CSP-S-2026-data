#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
struct node{
	int x,num,fir;
}a[N+5];
int fun1(int x){
	int sum=0;
	while(x){
		if(x%2==1)	sum++;
		x/=2;
	}
	return sum;
}
int fun2(int x){
	int sum=0;
	while(x){
		x=x>>2;
		sum++;
	}
	return sum;
}
bool cmp(node x,node y){
	if(x.num==y.num){
		if(x.fir==y.fir)	return x.x>y.x;
		return x.fir>y.fir;
	}
	return x.num>y.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].num=fun1(a[i].x);
		a[i].fir=fun2(a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	long long sum=a[1].x;
	for(int i=2;i<=m;i++){
		sum=sum&a[i].x;
	}
	cout<<sum;
	return 0;
}
