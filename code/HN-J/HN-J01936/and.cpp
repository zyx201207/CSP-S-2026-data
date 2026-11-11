#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
struct number{
	int num;
	int n1;
}a[200005];
bool cmp_by_n1(number x,number y){
	if(x.n1==y.n1){
		return x.num>y.num;
	}
	return x.n1>y.n1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].num;
		int tmp=a[i].num;
		while(tmp){
			if(tmp%2==1){
				a[i].n1++;
			}
			tmp/=2;
		}
	}
	sort(a,a+n,cmp_by_n1);
	if(m==1){
		cout<<a[0].num;
		return 0;
	}
	int sum=(a[0].num&a[1].num);
	for(int i=2;i<m;i++){
		sum=(sum&a[i].num);
	}
	cout<<sum;
	return 0;
}
