#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct U{
	long long x,f;
}a[200005];
long long math(long long i){
	long long sum=0,t=i;
	while(t){
		if(t%2==0){
			sum++;
		}
		t/=2;
	}
	return sum;
}
bool cmp(U i,U j){
	if(i.x==i.x){
		return i.f<j.f;
	}
	return i.x>j.x;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ma=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].f=math(a[i].x);
	}
	sort(a+1,a+1+n,cmp);
//	for(long long i=1;i<=n;i++){
//		cout<<a[i].x<<' ';
//	}
	long long sum=a[1].x;
	for(long long i=2;i<=m;i++){
		sum=sum&a[i].x;
	}
	cout<<sum;
//	fclose(stdin);
//	fclose(stdout); 
	return 0;
}
/*
4 2
3 15 12 12
*/
